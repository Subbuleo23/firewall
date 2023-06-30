#ifndef _VM_H
#define _VM_H

#include <stdint.h>
#include "const.h"


class VM {
public:
    VM();
public:
    uint16_t curr_proc_id;
    uint16_t players;
    uint8_t arena[CORE_SIZE];
};

#define AND0(x, y) -44*(x&y)*(x&y)-11*(x&y)*(x&~y)-77*(x&y)*~(x&y)+22*(x&y)*~(x|y)+33*(x&y)*~(x|~y)+44*(x&y)*~y+14*(x&~y)*(x&y)-77*(x&~y)*(x&~y)+63*(x&~y)*~(x&y)-98*(x&~y)*~(x|y)-49*(x&~y)*~(x|~y)+28*(x&~y)*~y+28*x*(x&y)+7*x*(x&~y)+49*x*~(x&y)-14*x*~(x|y)-21*x*~(x|~y)-28*x*~y-6*~(x^y)*(x&y)+33*~(x^y)*(x&~y)-27*~(x^y)*~(x&y)+42*~(x^y)*~(x|y)+21*~(x^y)*~(x|~y)-12*~(x^y)*~y+6*~(x|y)*(x&y)-33*~(x|y)*(x&~y)+27*~(x|y)*~(x&y)-42*~(x|y)*~(x|y)-21*~(x|y)*~(x|~y)+12*~(x|y)*~y+33*(x&y)*(x|y)-21*(x&~y)*(x|y)-21*x*(x|y)+9*~(x^y)*(x|y)-9*~(x|y)*(x|y)
#define AND1(x, y) 24*(x&y)*(x&y)-24*(x&y)*(x&~y)+24*(x&y)*~(x|y)-4*(x&y)*~(x|~y)+24*(x&~y)*(x&y)-24*(x&~y)*(x&~y)+24*(x&~y)*~(x|y)-4*(x&~y)*~(x|~y)+6*(x^y)*(x&y)-6*(x^y)*(x&~y)+6*(x^y)*~(x|y)-1*(x^y)*~(x|~y)-40*(x|y)*(x&~y)+40*(x|y)*y-20*(x|y)*~(x^y)+40*(x|y)*~(x|y)-55*(x|y)*~(x|~y)+24*~(x|~y)*(x&y)-24*~(x|~y)*(x&~y)+24*~(x|~y)*~(x|y)-4*~(x|~y)*~(x|~y)+28*(x&y)*(x^y)-20*(x&y)*~(x&~y)+28*(x&~y)*(x^y)-20*(x&~y)*~(x&~y)+7*(x^y)*(x^y)-5*(x^y)*~(x&~y)+35*(x|y)*(x^y)-25*(x|y)*~(x&~y)+28*~(x|~y)*(x^y)-20*~(x|~y)*~(x&~y)
#define AND2(x, y) -8*(x&y)*(x&y)-8*(x&y)*(x&~y)-10*(x&y)*~(x|y)-3*(x&y)*~(x|~y)+140*(x&~y)*(x&y)-56*(x&~y)*(x&~y)-196*(x&~y)*y-28*(x&~y)*~(x&~x)-84*(x&~y)*~(x|y)+210*(x&~y)*~(x|~y)-56*(x^y)*(x&y)-56*(x^y)*(x&~y)-70*(x^y)*~(x|y)-21*(x^y)*~(x|~y)+70*~(x|y)*(x&y)-28*~(x|y)*(x&~y)-98*~(x|y)*y-14*~(x|y)*~(x&~x)-42*~(x|y)*~(x|y)+105*~(x|y)*~(x|~y)+56*~(x|~y)*(x&y)+56*~(x|~y)*(x&~y)+70*~(x|~y)*~(x|y)+21*~(x|~y)*~(x|~y)-70*~y*(x&y)+28*~y*(x&~y)+98*~y*y+14*~y*~(x&~x)+42*~y*~(x|y)-105*~y*~(x|~y)+7*(x&y)*(x|~y)+2*(x&y)*~x+98*(x&~y)*(x|~y)+28*(x&~y)*~x+49*(x^y)*(x|~y)+14*(x^y)*~x+49*~(x|y)*(x|~y)+14*~(x|y)*~x-49*~(x|~y)*(x|~y)-14*~(x|~y)*~x-49*~y*(x|~y)-14*~y*~x
#define ADD0(x, y) 3*(x&y)*(x&y)-6*(x&y)*(x&~y)+2*(x&y)*(x^y)-2*(x&y)*~(x&~x)-4*(x&y)*~(x|y)+1*(x&y)*~(x|~y)+2*(x&~y)*(x&y)+24*(x&~y)*(x&~y)-8*(x&~y)*(x^y)+16*(x&~y)*~(x|y)+10*(x&~y)*~(x|~y)+3*x*(x&y)-6*x*(x&~y)+2*x*(x^y)-2*x*~(x&~x)-4*x*~(x|y)+1*x*~(x|~y)-12*~(x&~x)*(x&y)+24*~(x&~x)*(x&~y)-8*~(x&~x)*(x^y)+8*~(x&~x)*~(x&~x)+16*~(x&~x)*~(x|y)-4*~(x&~x)*~(x|~y)+12*~(x|y)*(x&y)-24*~(x|y)*(x&~y)+8*~(x|y)*(x^y)-8*~(x|y)*~(x&~x)-16*~(x|y)*~(x|y)+4*~(x|y)*~(x|~y)+3*~(x|~y)*(x&y)+36*~(x|~y)*(x&~y)-12*~(x|~y)*(x^y)+24*~(x|~y)*~(x|y)+15*~(x|~y)*~(x|~y)+7*(x&y)*~y-14*(x&~y)*~y+7*x*~y-28*~(x&~x)*~y+28*~(x|y)*~y-21*~(x|~y)*~y
#define ADD1(x, y) 2*(x&y)*(x&y)+4*(x&y)*(x&~y)+2*(x&y)*(x^y)+6*(x&y)*~(x|y)+4*(x&y)*~(x|~y)+27*(x&~y)*(x&y)+36*(x&~y)*(x&~y)-15*(x&~y)*(x^y)-24*(x&~y)*x-3*(x&~y)*~(x|y)+12*(x&~y)*~(x|~y)-4*(x|~y)*(x&y)-8*(x|~y)*(x&~y)-4*(x|~y)*(x^y)-12*(x|~y)*~(x|y)-8*(x|~y)*~(x|~y)-63*~(x|y)*(x&y)-84*~(x|y)*(x&~y)+35*~(x|y)*(x^y)+56*~(x|y)*x+7*~(x|y)*~(x|y)-28*~(x|y)*~(x|~y)-108*~(x|~y)*(x&y)-144*~(x|~y)*(x&~y)+60*~(x|~y)*(x^y)+96*~(x|~y)*x+12*~(x|~y)*~(x|y)-48*~(x|~y)*~(x|~y)+99*~x*(x&y)+132*~x*(x&~y)-55*~x*(x^y)-88*~x*x-11*~x*~(x|y)+44*~x*~(x|~y)-4*(x&y)*~(x&y)+6*(x&~y)*~(x&y)+8*(x|~y)*~(x&y)-14*~(x|y)*~(x&y)-24*~(x|~y)*~(x&y)+22*~x*~(x&y)
#define ADD2(x, y) 3*(x&y)*(x&y)+18*(x&y)*(x&~y)-15*(x&y)*~(x&y)+39*(x&y)*~(x|y)+39*(x&y)*~(x|~y)-15*(x&~y)*(x&y)-24*(x&~y)*(x&~y)+9*(x&~y)*~(x&y)+18*(x&~y)*~(x&~x)-45*(x&~y)*~(x|y)-45*(x&~y)*~(x|~y)+20*~(x&~x)*(x&y)+32*~(x&~x)*(x&~y)-12*~(x&~x)*~(x&y)-24*~(x&~x)*~(x&~x)+60*~(x&~x)*~(x|y)+60*~(x&~x)*~(x|~y)-1*~(x^y)*(x&y)-6*~(x^y)*(x&~y)+5*~(x^y)*~(x&y)-13*~(x^y)*~(x|y)-13*~(x^y)*~(x|~y)+5*~(x|y)*(x&y)+30*~(x|y)*(x&~y)-25*~(x|y)*~(x&y)+65*~(x|y)*~(x|y)+65*~(x|y)*~(x|~y)+3*~(x|~y)*(x&y)+18*~(x|~y)*(x&~y)-15*~(x|~y)*~(x&y)+39*~(x|~y)*~(x|y)+39*~(x|~y)*~(x|~y)-21*(x&y)*~x+21*(x&~y)*~x-28*~(x&~x)*~x+7*~(x^y)*~x-35*~(x|y)*~x-21*~(x|~y)*~x)
#define SUB0(x, y) 24*(x&y)*(x&~y)-24*(x&y)*y+12*(x&y)*~(x&~y)-84*(x&y)*~(x|y)-72*(x&~y)*(x&~y)+120*(x&~y)*~(x|y)+66*x*(x&~y)-110*x*~(x|y)-30*~(x^y)*(x&~y)+50*~(x^y)*~(x|y)+30*~(x|y)*(x&~y)-50*~(x|y)*~(x|y)-4*~(x|~y)*(x&~y)+4*~(x|~y)*y-2*~(x|~y)*~(x&~y)+14*~(x|~y)*~(x|y)+36*(x&y)*(x&y)-30*(x&y)*x-60*(x&y)*~(x|~y)+66*(x&y)*~x-72*(x&~y)*(x&y)+60*(x&~y)*x+120*(x&~y)*~(x|~y)-132*(x&~y)*~x+66*x*(x&y)-55*x*x-110*x*~(x|~y)+121*x*~x-30*~(x^y)*(x&y)+25*~(x^y)*x+50*~(x^y)*~(x|~y)-55*~(x^y)*~x+30*~(x|y)*(x&y)-25*~(x|y)*x-50*~(x|y)*~(x|~y)+55*~(x|y)*~x-6*~(x|~y)*(x&y)+5*~(x|~y)*x+10*~(x|~y)*~(x|~y)-11*~(x|~y)*~x
#define SUB1(x, y) -5*~(x|y)*(x&y)+5*~(x|y)*(x^y)+45*~(x|~y)*(x&y)-15*~(x|~y)*(x^y)-50*~(x|~y)*~(x^y)+40*~(x|~y)*~(x|y)-54*~x*(x&y)+18*~x*(x^y)+60*~x*~(x^y)-48*~x*~(x|y)+9*~y*(x&y)-3*~y*(x^y)-10*~y*~(x^y)+8*~y*~(x|y)-5*~(x|y)*(x&~y)-5*~(x|y)*~(x&y)-5*~(x|y)*~(x|~y)+5*~(x|~y)*(x&~y)+5*~(x|~y)*~(x&y)+5*~(x|~y)*~(x|~y)-6*~x*(x&~y)-6*~x*~(x&y)-6*~x*~(x|~y)+1*~y*(x&~y)+1*~y*~(x&y)+1*~y*~(x|~y)
#define SUB2(x, y) -77*(x&y)*(x&y)+77*(x&y)*~(x&~y)-77*(x&y)*~(x|y)-70*(x&~y)*(x&y)+70*(x&~y)*~(x&~y)-70*(x&~y)*~(x|y)+77*(x|~y)*(x&y)-77*(x|~y)*~(x&~y)+77*(x|~y)*~(x|y)+25*~(x|y)*(x&y)+20*~(x|y)*(x&~y)-10*~(x|y)*(x^y)-15*~(x|y)*~(x&~y)+25*~(x|y)*~(x|y)+35*~(x|~y)*(x&y)-35*~(x|~y)*~(x&~y)+35*~(x|~y)*~(x|y)-42*~x*(x&y)+42*~x*~(x&~y)-42*~x*~(x|y)+11*(x&y)*~(x&~x)-77*(x&y)*~(x|~y)+10*(x&~y)*~(x&~x)-70*(x&~y)*~(x|~y)-11*(x|~y)*~(x&~x)+77*(x|~y)*~(x|~y)-5*~(x|y)*~(x&~x)+35*~(x|y)*~(x|~y)-5*~(x|~y)*~(x&~x)+35*~(x|~y)*~(x|~y)+6*~x*~(x&~x)-42*~x*~(x|~y)


#endif