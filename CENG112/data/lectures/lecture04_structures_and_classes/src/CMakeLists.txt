project(ceng112_04 CXX)

add_executable(static-contact contact.cc static_contact.cc)
add_executable(dynamic-contact contact.cc dynamic_contact.cc)
add_executable(contact-with-classes contact_item.cc contact_with_classes.cc)
add_executable(intarray-test intarray.cc intarraytest.cc)
add_executable(array-test array_test.cc)

set(CMAKE_BUILD_TYPE Debug)
