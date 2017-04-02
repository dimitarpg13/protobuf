#include "person.pb.h"


int main()
{
	Person person;
	person.set_name("Hans Mustermann");

	person.set_email("hans@muster.mann");

	// std::string *name = person.mutable_name();
	// *name = "Hans Mustermann";

	Person::PhoneNumber *phone;
	phone = person.add_phone();
	phone->set_number("030 12345678");
	phone->set_type(Person::WORK);
	phone = person.add_phone();
	phone->set_number("0170 987654321");
	phone->set_type(Person::MOBILE);

	// check for validity: person.IsInitialized() == true ?

}
