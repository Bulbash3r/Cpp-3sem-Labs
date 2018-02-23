#pragma once
#include <string>
#include <iostream>
#include "List.h"
#include "tourist.h"

using namespace std;

template <typename T>
class Algorithm
{
public:
		template <typename T> friend class List;
		static void Find(T &tmp, List<T> &list)
		{
				int d = 0;
				List<T> a;
				Iterator<T> it = list.begin();
				Iterator<T> jt = list.end();
				jt++;
				while (it != jt)
				{
						if ((*it) == tmp)
						{
								a.push_tail(*it);
								d++;
						}
						it++;
				}
				if (!d) cout << "Ёлемент не найден" << endl;
				else
				{
						system("cls");
						a.output();
						system("pause");
				}
				return;
		}

		static T FindName(string tmp, List<T> &list)
		{
				Iterator<T> it = list.begin();
				Iterator<T> jt = list.end();
				jt++;
				while (it != jt)
				{
						if ((*it).getName() == tmp)
						{
								return (*it);
						}
						it++;
				}
				cout << "Ёлемент не найден" << endl;
		}

		static T FindAge(int tmp, List<T> &list)
		{
				Iterator<T> it = list.begin();
				Iterator<T> jt = list.end();
				jt++;
				while (it != jt)
				{
						if ((*it).getAge() == tmp)
						{
								return (*it);
						}
						it++;
				}
				cout << "Ёлемент не найден" << endl;
		}


		void sortAge(List<T> &list)
		{
				Iterator<cTourist> it = list.begin();
				Iterator<cTourist> jt = list.end();
				while (it!=jt)
				{
						Iterator<cTourist> tmp = it;
						tmp++;
						if (((*it).getAge()) > ((*tmp).getAge()))
						{
								T temp = *tmp;
								*tmp = *it;
								*it = temp;

								it++;
								sortAge(list);
						}
						else { it++; }
				}
		}
		void sortName(List<T> &list)
		{
				Iterator<cTourist> it = list.begin();
				Iterator<cTourist> jt = list.end();
				while (it != jt)
				{
						Iterator<cTourist> tmp = it;
						tmp++;
						if (((*it).getName()) > ((*tmp).getName()))
						{
								T temp = *tmp;
								*tmp = *it;
								*it = temp;

								it++;
								sortAge(list);
						}
						else { it++; }
				}
		}

		void sortAll(List<T> &list, int *ms)
		{
				Iterator<cTourist> it = list.begin();
				Iterator<cTourist> jt = list.end();
				//jt++;
				Iterator<cTourist> it2 = it;
				for (it;it!=jt;it++)
						for (it2; it2 != jt; it2++)
						{
								bool flag = false;
								if (((*it).getName()) >= ((*it2).getName()) || ms[0] == 0)
								{
										flag = true;
										if (((*it).getLastName()) >= ((*it2).getLastName()) || ms[1] == 0)
										{
												flag = true;
												if (((*it).getAge()) >= ((*it2).getAge()) || ms[2] == 0)
												{
														flag = true;
														if (((*it).getPassport()) >= ((*it2).getPassport()) || ms[3] == 0)
														{
																flag = true;
																if (((*it).getCountry()) >= ((*it2).getCountry()) || ms[4] == 0)
																{
																		flag = true;
																		if (((*it).getDate()) >= ((*it2).getDate()) || ms[5] == 0)
																		{
																				flag = true;
																		}
																}
														}
												}
										}
								}
								if (flag)
								{
										T temp = *it2;
										*it2 = *it;
										*it = temp;

								}
						}
		}
};
