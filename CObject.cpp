#include "CObject.h"

str TypeToString(TypeCode type) {
	switch (type)
	{
	case TypeCode::String:
		return "String";
	case TypeCode::Int32:
		return "Int32";
	case TypeCode::Char:
		return "Char";
	case TypeCode::Float32:
		return "Float32";
	case TypeCode::Instance:
		return "Instance";
	default:
		return null;
	}
}

Object::Object(str value) {
	Box = (unknow)value;
	Type = TypeCode::String;
	Size = sizeof(value);
}
Object::Object(int value) {
	Box = (unknow)value;
	Type = TypeCode::Int32;
	Size = 4;
}
Object::Object(char value) {
	Box = (unknow)value;
	Type = TypeCode::Char;
	Size = 1;
}
Object::Object(float value) {
	Box = (unknow)&value;
	Type = TypeCode::Float32;
	Size = 4;
}
Object::Object(unknow value) {
	Box = (unknow)value;
	Size = sizeof(&value);
	Type = TypeCode::Instance;
}

TypeCode Object::GetType() {
	return Type;
}
size_t Object::GetSize() {
	return Size;
}
Object::operator str() {
	if (Type == TypeCode::String)
		return *(str*)&Box;
	return null;
}
Object::operator int() {
	if (Type == TypeCode::Int32)
		return *(int*)&Box;
	return null;
}
Object::operator char() {
	if (Type == TypeCode::Char)
		return *(char*)&Box;
	return null;
}
Object::operator float() {
	if (Type == TypeCode::Float32)
		return *(float*)&Box;
	throw null;
}

unknow Object::Unbox() {
	return Box;
}
str Object::ToString() {
	if (Type == TypeCode::String)
		return *(str*)&Box;
	return null;
}
int Object::ToInt32() {
	if (Type == TypeCode::Int32)
		return *(int*)&Box;
	return null;
}
char Object::ToChar() {
	if (Type == TypeCode::Char)
		return *(char*)&Box;
	return null;
}
float Object::ToFloat32() {
	if (Type == TypeCode::Float32)
		return *(float*)&Box;
	return null;
}