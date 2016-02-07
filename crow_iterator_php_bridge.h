#ifndef CROW_ITERATOR_PHP_BRIDGE_H
#define CROW_ITERATOR_PHP_BRIDGE_H

#include <phpcpp.h>
#include <dao/inc/row.h>

class CRowsPhpBridgeIterator : public Php::Base {

public:

    CRowsPhpBridgeIterator(synopsis::TRows& rows);
    virtual ~CRowsPhpBridgeIterator();

    inline void first() { m_tszCurrent = 0; }
    inline void next() { ++m_tszCurrent; }
    Php::Value currentItem();
    Php::Value isDone() const { return m_tszCurrent >= m_rows.size(); }

private:
    synopsis::TRows& m_rows;
    size_t m_tszCurrent;
};


#endif // CROW_ITERATOR_PHP_BRIDGE_H
