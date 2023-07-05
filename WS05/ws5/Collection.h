/**
 * @file Collection.cpp
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

using namespace std;

namespace sdds {

	template <typename T>
	class Collection {
		string _name {};
		T* _item {};
		size_t _cnt {};
		void (*_observer)(const Collection<T>&, const T&) { nullptr };
	public:
		explicit Collection(const std::string& name) {
			_name = name;
			_item = nullptr;
			_cnt = 0;
			_observer = nullptr;
		}
		Collection(Collection&) = delete;
		Collection& operator=(Collection&) = delete;
		~Collection() {
			delete[] _item;
			_item = nullptr;
		}
		const std::string& name() const { return _name; }
		size_t size() const { return _cnt; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) { _observer = observer; }

		Collection<T>& operator+=(const T& item) {
			bool exist = false;
			for (size_t i = 0; i < _cnt; ++i) {
				if (_item[i].title() == item.title()) {
					exist = true;
				}
			}
			if (!exist) {
				if (_cnt == 0) {
					_cnt++;
					_item = new T[_cnt];
					_item[0] = item;
				}
				else {
						T * temp = new T[_cnt];
					for (size_t i = 0; i < _cnt; ++i) {
						temp[i] = _item[i];
					}
					delete[] _item;
					_cnt++;
					_item = new T[_cnt];
					for (size_t j = 0; j < _cnt - 1; ++j) {
						_item[j] = temp[j];
					}
					delete[] temp;
					_item[_cnt - 1] = item;
					if (_observer != nullptr) {
						_observer(*this, item);
					}
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			
			if (idx >= _cnt || idx < 0) {
				throw std::out_of_range("Bad index [" + to_string(idx) + "]. " + "Collection has [" + to_string(_cnt) + "] items.");
			}
			else {
				return _item[idx];
			}
		}
		T* operator[](std::string title) const {
			int idx = -1;
			for (size_t i = 0; i < _cnt; ++i) {
				if (_item[i].title() == title) {
					idx = i;
				}
			}
			if (idx == -1) {
				return nullptr;
			}
			else {
				return &_item[idx];
			}
		}
		friend ostream& operator<<(ostream& os, Collection& src) {
			for (size_t i = 0; i < src.size(); ++i) {
				os << src._item[i]; 
			}
			return os;
		}
	};
}

#endif