#pragma once
#include "User.h"

class Message
{
	const std::string _fromUser;
	const std::string _toUser;
	const std::string _textmessage;
public:
	//Message(const std::string& fromUser, const std::string& toUser, const std::string& textmessage) : _fromUser(fromUser), _toUser(toUser), _textmessage(textmessage)

	const std::string &getfromUser() const { return _fromUser; }
	const std::string &gettoUser() const { return _toUser; }
	const std::string& gettextmessage() const { return _textmessage; }
};