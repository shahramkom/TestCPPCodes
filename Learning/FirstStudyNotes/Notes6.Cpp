 // std::chrono::system_clock:  current time according to the system (it is not steady)
 // std::chrono::steady_clock:  goes at a uniform rate (it can't be adjusted)
 // std::chrono::high_resolution_clock: provides smallest possible tick period. 
//  std:chrono::duration<>:  represents time duration

 std::ratio<1,10>  r; //  1/10  1 divided 10
cout << r.num << "/" << r.den << endl;  // num = 1   den = 10

cout << chrono::system_clock::period::num << "/" << chrono::system_clock::period::den << endl;   // 1/10000000


//RANDOM
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine e(seed);
printRandomm(e);//print 10 number random

std::shuffle(v.begin , v.end , std::default_random_engine()); //shuffle vector v
//???modes of random number generation
//    linear,subtract,independent,shuffle,default,...

std::uniform_int_distribution<int> distr(0,5);  // range: [0,5]  -- both 1 and 5 are included
													// default param: [0, INT_MAX]
//???modes of distributions of random number generation
//    normal,bernoli,poission,geometric,...


//REG EX
regex e("abc") //exact need abc
regex e("abc",regex::constant::icase) //all modes of abc , ABC,aBC , abC , ...
regex e("abc.",regex::constant::icase) //any character after abc
regex e("abc?",regex::constant::icase) //zero or one preceding character after abc  >>>> correct ab, not correct abccc
regex e("abc*",regex::constant::icase) //zero or more preceding character after abc >>>> correct ab , abcccccc
regex e("abc+",regex::constant::icase) //one of more preceding character after abc  >>>> correct abc , not correct ab
regex e("ab[cd]",regex::constant::icase) //any number of characters c,d   >>>> correct abc , ab , abcccddd , abdd , abcddd , not correct aabc
regex e("ab[^cd]*",regex::constant::icase) //any characters except c,d   >>>> correct abe , ab , absdc , abeeee , not correct abc ,abd
regex e("ab[cd]{3}",regex::constant::icase) //exact 3 c,d   >>>> correct abddd , abccc , abcdc  , not correct abcdcd ,abd , abcd
regex e("ab[cd]{3,}",regex::constant::icase) //   >>>> correct abcdd , abcddddd , abcccccc  , not correct abcdcd ,abd , abcd
regex e("abc|de[fg]",regex::constant::icase) // | means or    >>>> correct abc , def , deg  , not correct dab , abcdef
regex e("(abc)de+\\1",regex::constant::icase) // \1 means first group    >>>> correct abcdeeabc 
regex e("(ab)c(de+)\\2\\1",regex::constant::icase) // \1 means first group    >>>> correct abcdeeedeeeab not: abcdeeedeeab
regex e("[[:w:]]+@[[:w:]]+\.com",regex::constant::icase) // [[:w:]] means word character : digit , number , or underscore    >>>> correct a@b.com not: a@b.org

regex_match(str , e);
regex_search(str , e);

//memory
//review
    //* Unique ptr
    //* weak ptr

