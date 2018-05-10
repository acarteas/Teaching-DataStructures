#ifndef HASHER_BASE_H
#define HASHER_BASE_H

template <typename HashType>
class HasherBase
{
public:
	virtual int getHash(const HashType &item, int mod_by) = 0;
};

#endif