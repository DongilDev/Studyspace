#include <assert.h>

template<typename T>
class CArr
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);

	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);


	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

	void clear()
	{
		m_iCount = 0;  // 공간이 크게 늘어나 있는 상태
		               // 이런거 해결하려고 vector 같은 경우는 swap 을 쓴다던지 하는데 나중에 얘기해주신다 함.
	}

public:
	CArr();
	~CArr();


	// inner 클래스를 포함하고 있는 클래스의 private 멤버 접근 가능
	class iterator
	{
	private:
		CArr* m_pArr; // iterator 가 가리킬 데이터를 관리하는 가변배열 주소
		T* m_pData;   // 데이터들의 시작 주소
		int m_iIdx;   // 가리키는 데이터의 인덱스
		bool m_bValid; // iterator 유효성 체크

	public:
		T& operator * ()
		{
			// iterator 가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 인 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// ++ 전위
		iterator& operator ++()
		{
			// end iterator 인 경우
			// iterator 가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);
			
			// iterator 가 마지막 데이터를 가리키고 있는 경우
			// --> end iterator 가 된다.
			if(m_pArr->size() - 1 ==m_iIdx )
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++ 후위
		iterator operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		// -- 전위
		iterator& operator --()
		{
			// iIdx 가 -1 인 경우
			// iterator 가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);

			// iterator 가 첫번째 데이터를 가리키고 있는경우
			// --> iIdx 가 -1 이 된다.
			if (0 == m_iIdx)
				m_iIdx = -1;
			else
				--m_iIdx;

			return *this;
		}

		// -- 후위
		iterator operator --(int)
		{
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}

		// 비교연산자 ==, !=
		bool operator ==(const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}

			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

	public:
		iterator()
			: m_pArr(nullptr), m_pData(nullptr), m_iIdx(-1), m_bValid(false)
		{
			
		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr), m_pData(_pData), m_iIdx(_iIdx), m_bValid(false)
		{
			if (nullptr != _pArr && 0 <=_iIdx)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CArr;
	};
};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr), m_iCount(0), m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// 힙 영역에 할당한 공간이 다 참
	if (m_iMaxCount <= m_iCount)
	{
		// 재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우 (예외 처리
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	m_pData = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// 시작을 가리키는 iterator 를 만들어서 반환해줌
	if(0==m_iCount)
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end()
	else
		return iterator(this, m_pData, 0);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 끝의 다음을 가리키는 iterator 를 만들어서 반환해줌
		return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// iterator 가 다른 Arr 쪽 요소를 가리키는 경우
	// iterator 가 end tierator 인 경우
	if ( this != _iter.m_pArr || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}

	// iterator 가 가리키는 데이터를 배열 내에서 제거한다. 
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}
	
	_iter.m_bValid = false;

	// 카운트 감소
	--m_iCount;  

	return iterator(this, m_pData, _iter.m_iIdx);
}