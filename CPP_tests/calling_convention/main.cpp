#include <iostream>
#include <string>

extern "C" int to_wrap(char *s, float *f);

extern "C" int to_wrap_good(char *s, float f);

extern "C" void f_ezsetval_(const char *, float f);

extern "C" int c_ezsetval(const char *s, float f);

// extern "C" int c_ezsetval2(const char *s, float * f);

inline static void wrapper_function(std::string s, float f)
{
    to_wrap(&s[0], &f);
}

inline static void wrapper_function_good(std::string s, float f)
{
    to_wrap_good(&s[0], f);
}

void many_float_params(float f1, float f2, float f3)
{
   
}

int main(void)
{
   std::string s = "The constant pi";
    float f = 3.1415;
    // const char *c_str = s.c_str();

    // f_ezsetval_(c_str, f);
    c_ezsetval(s.c_str(), f);

    wrapper_function(s,f);
    wrapper_function_good(s,f);
    wrapper_function(s,f);
}
