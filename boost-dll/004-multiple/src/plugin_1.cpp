#include <plugin_1.hpp>

#include <boost/dll/alias.hpp>

#include <iostream>
#include <memory>


// 4e08e426-ed3b-496a-8443-774ef4598212
uuid_t plugin_1::uuid() const noexcept
{
  return { 
    0x4e, 0x08, 0xe4, 0x26,
    0xed, 0x3b,
    0x49, 0x6a,
    0x84, 0x43,
    0x77, 0x4e, 0xf4, 0x59, 0x82, 0x12,
  };
}

str_t plugin_1::name() const noexcept
{
  return "plugin 1";
}

bool plugin_1::exec()
{
  std::cout << "plugin_1::exec()" << std::endl;

  return true;
}

std::shared_ptr<plugin_base> private_create_plugin()
{
  auto ptr = std::make_shared<plugin_1>();

  return std::dynamic_pointer_cast<plugin_base>(ptr);
}

BOOST_DLL_ALIAS(private_create_plugin, create_plugin);
