#include <plugin_base.hpp>
#include <boost/filesystem.hpp>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/uuid/uuid_io.hpp>
#include <iostream>


namespace dll = boost::dll;
namespace fs  = boost::filesystem;

int main()
{
  auto current_path = fs::current_path();
  auto parent_path = current_path.parent_path();
  auto lib_path = parent_path / "lib";

  auto factory = dll::import<factory_t>(
    lib_path / "plugin",
    "create_plugin",
    dll::load_mode::append_decorations
  );

  auto plugin = factory();

  std::cout << "uuid: " << plugin->uuid() << std::endl;
  std::cout << "name: " << plugin->name() << std::endl;

  plugin->exec();

  return 0;
}
