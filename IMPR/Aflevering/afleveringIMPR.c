#include <stdio.h>

// Håber ikke at static gør noget dårligt andet end at gøre variablen public
static int sec_per_week = 604800;
static int sec_per_day = 86400;
static int sec_per_hour = 3600;
static int sec_per_min = 60;
static int sec = 0;

// Prøvede bare at lave en funktion :))
int remaind(int s, int n)
{
    int sec_remainder;

    if(n == 1)
    {
        s = sec;
        return(s);
    }
    else if(n == 2)
    {
        s = sec % sec_per_hour;
        return(s);
    }
    else if (n == 3)    
    {
        s = (sec % sec_per_hour) % sec_per_min;
        return(s);
    }
    else
    {
        s = s;
        return(s);
    }
}


int main(void)
{
int min = 0;
int hour = 0;

printf("How many seconds shall i recalculate for you? ");
scanf("%d", &sec);

hour = remaind(sec, 1) / sec_per_hour;
min = remaind(sec, 2) / sec_per_min;
sec = remaind(sec, 3);

if(hour > 1) 
{
    printf(sec > 0 && min > 0 ? "%d hours, " : "%d hours and ", hour);
}
else if(hour == 1)
{
    printf(sec > 0 && min > 0 ? "%d hour, " : sec == 0 && min == 0 ? "%d hour" : "%d hour and", hour);
}
else(hour == 0);
{
    printf("");
}

if(min > 1) 
{
    printf(sec > 0 ? "%d minutes and " : "%d minutes", min);
}
else if(min == 1)
{
    printf(sec > 0 ? "%d minute and " : "%d minute", min);
}
else(min == 0);
{
    printf("");
}

printf(sec > 1 ? "%d secouds" : sec == 1 ? "%d secoud" : "", sec);

printf("\n");

return(0);
}