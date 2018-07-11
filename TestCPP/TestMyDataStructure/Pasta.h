#pragma once
class Pasta
{
public:
	Pasta();
	Pasta(Pasta& other);
	void operator=(void* dataType);
	~Pasta();
private:
	uint8_t uint8t_;
	uint16_t uint16t_;
	uint32_t uint32t_;
	uint64_t uint64t_;
	string   string_;
	wstring  wstring_;
};

