#define unknow void*
#define str const char*
#define null 0

enum class TypeCode
{
	String,
	Int32,
	Char,
	Float32,
	Instance,
};

str TypeToString(TypeCode type);

struct Object
{
private:
	unknow Box;
	TypeCode Type;
	size_t Size;
public:
	Object(str value);
	Object(int value);
	Object(char value);
	Object(float value);
	Object(unknow value);
	unknow Unbox();
	str ToString();
	int ToInt32();
	char ToChar();
	float ToFloat32();
	TypeCode GetType();
	size_t GetSize();
	operator str();
	operator int();
	operator char();
	operator float();
	template<typename type> type Cast() {
		return *(type*)&Box;
	}
};