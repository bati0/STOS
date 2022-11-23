#include "iostream"
int my_strlen(const char *str)
{
    const char *s;

    for (s = str; *s; ++s)
            ;
    return (s - str);
}
//zakonczy sie gdy petla trafi na znak null.

int my_strcpy(const char *str,char *dest)
{
    const char *s;

    for (s = str; *s; ++s, ++dest)
        *dest = *s;


    return (s - str);
}

int main(){
    char* napis = "ala ma kota";
    char kopia[20] = "jest bardzp pusto";
    std::cout <<  my_strlen(napis) << std::endl;
    std::cout <<  my_strlen(kopia)  << std::endl;

    my_strcpy(napis,kopia);


    std::cout <<  napis << my_strlen(napis) << " " <<  std::endl;
    std::cout <<  kopia <<  my_strlen(kopia) << " " <<  std::endl;
}
