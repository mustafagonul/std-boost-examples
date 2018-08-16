#include <plugin_2.hpp>

#include <boost/dll/alias.hpp>

#include <iostream>
#include <memory>


// 374e2ea2-96c7-45ed-812d-db4663afdd49
uuid_t plugin_2::uuid() const noexcept
{
  return {
    0x37, 0x4e, 0x2e, 0xa2,
    0x96, 0xc7,
    0x45, 0xed,
    0x81, 0x2d,
    0xdb, 0x46, 0x63, 0xaf, 0xdd, 0x49,
  };
}

str_t plugin_2::name() const noexcept
{
  return "plugin 2";
}

bool plugin_2::exec()
{
  std::cout << "plugin_2::exec()" << std::endl;

  return true;
}

std::shared_ptr<plugin_base> private_create_plugin()
{
  auto ptr = std::make_shared<plugin_2>();

  return std::dynamic_pointer_cast<plugin_base>(ptr);
}

BOOST_DLL_ALIAS(private_create_plugin, create_plugin);
