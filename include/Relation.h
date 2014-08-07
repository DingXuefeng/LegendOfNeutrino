/*****************************************************************
 * The class representing relation between two things
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.25 ver 1.0
 *****************************************************************/
#ifndef Relation_H
#define Relation_H
#include "Point.h"
#include <vector>
#include <iostream>
#include <stdexcept>
template<typename X,typename Y>
class Relation
{
  public:
    // insert a point into the relation
    void insert(const Point<X,Y>& point);
    // whether x is inside
    Point<X,Y>* findX(const X& x) const;
    // modify a point
    // if it does not have the x, it will throw an exception
    void setPoint(const X& x,const Y& y);
    // get the y value for some x
    // if it does not have the x, it will throw an exception
    const Y& getY(const X& x) const;
    // get the whole relation
    inline const std::vector<Point<X,Y> >& getRelation() const { return relation;}
  private:
    void xNotin(const X& x) const;
  private:
    // private member holding the data
    std::vector<Point<X,Y> > relation;
};

template<typename X,typename Y>
void Relation<X,Y>::insert(const Point<X,Y>& point) 
{ 
  if(hasX(point.getX())==NULL)
    relation.push_back(point);
  else
  {
    std::cerr<<"[Relation::setPoint]\n"
      <<"Your X ["<<point->getX()<<"]"<<" is already inside the relation."<<std::endl;
    throw std::runtime_error("x alreay in");
  }
};

template<typename X,typename Y>
Point<X,Y>* Relation<X,Y>::findX(const X& x) const
{
  /*
  for(unsigned int i = 0; i<relation.size(); i++)
    if(relation[i].sameX(x)) return &(relation[i]);
    */
  for(typename std::vector<Point<X,Y> >::iterator relationit = relation.begin();
      relationit != relation.end(); relationit++)
    if(relationit->sameX(x)) return relationit;
  return NULL;
}

template<typename X,typename Y>
void Relation<X,Y>::setPoint(const X& x,const Y& y)
{
  try
  {
    hasX(x)->setY(y);
  }
  catch (const std::runtime_error& err)
  {
    xNotin(x);
  }
}

template<typename X,typename Y>
const Y& Relation<X,Y>::getY(const X& x) const
{
  try
  {
    return hasX(x)->getY();
  }
  catch (const std::runtime_error& err)
  {
    xNotin(x);
  }
}

template<typename X,typename Y>
void Relation<X,Y>::xNotin(const X& x) const
{
  std::cerr<<"[Relation::setPoint]\n"
    <<"Your X ["<<x<<"]"<<" is not inside the relation."<<std::endl;
  throw std::runtime_error("x not in");
}
#endif
