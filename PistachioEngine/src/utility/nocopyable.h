//
// Created by dz on 2023/3/1.
//

#ifndef PISTACHIO_NOCOPYABLE_H
#define PISTACHIO_NOCOPYABLE_H

class nocopyable
{
protected:
    nocopyable() {}
    ~nocopyable() {}

private:
    nocopyable(const nocopyable&);
    nocopyable& operator=(const nocopyable&);
};


#endif //PISTACHIO_NOCOPYABLE_H
