#include <plugin_base.hpp>
#include <boost/filesystem.hpp>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/uuid/uuid_io.hpp>
#include <iostream>


namespace dll = boost::dll;
namespace fs  = boost::filesystem;

using path_vector_t = std::vector<fs::path>;


void get_files(fs::path const& dir, path_vector_t& files)
{
  files.clear();

  if (fs::is_directory(dir) == false)
    return;

  fs::recursive_directory_iterator iter(dir), end;
  for (; iter != end; ++iter)
    if (fs::is_regular_file(*iter))
    files.push_back(*iter);
}

int main()
{
  auto current_path = fs::current_path();
  auto parent_path = current_path.parent_path();
  auto lib_path = parent_path / "lib";

  path_vector_t path_vector;
  get_files(lib_path, path_vector);

  for (auto const& path : path_vector) {
    // std::cout << path.string() << std::endl;

    auto factory = dll::import_alias<factory_t>(path, "create_plugin");
    auto plugin = factory();
    
    std::cout << "uuid: " << plugin->uuid() << std::endl;
    std::cout << "name: " << plugin->name() << std::endl;

    plugin->exec();
  }

  return 0;
}
