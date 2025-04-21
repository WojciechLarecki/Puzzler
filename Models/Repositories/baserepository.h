#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <vector>

template <typename T>
class RepositoryBase {
public:
    virtual ~RepositoryBase() = default;

    virtual bool Add(const T& entity) = 0;
    virtual bool Delete(int id) = 0;
    virtual std::vector<T> GetAll() = 0;
};

#endif // BASEREPOSITORY_H
