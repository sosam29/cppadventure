class IndexOutOfBoundException {};
class IntArray{
private:
    int* m_ptr{nullptr};
    int m_size{0};
public:
    IntArray()= default;

    explicit IntArray(int size){
        if (size != 0){
            m_ptr = new int[size]{};
            m_size = size;
        }
    }

    ~IntArray(){
        delete[] m_ptr;
    }

    int Size() const {
        return m_size;
    }

    bool IsEmpty() const{
        return (m_size ==0);
    }

    //setter/getter for index
    int& operator[](int i)
    {
        if (! IsValidRange(i))
        {
            throw IndexOutOfBoundException{};
        }
        return m_ptr[i];
    }

    // readonly accessor
    int operator[](int i) const{
        if (! IsValidRange(i))
        {
            throw IndexOutOfBoundException{};
        }
        return m_ptr[i];
    }

    bool IsValidRange(int i) const {
        return (i>= 0 && i< Size());
    }



    // IntArray (const IntArray& arr)
    // {
    //     if (!arr.IsEmpty())
    //     {
    //         m_size = arr.m_size;
    //         m_ptr = new int[m_size];

    //         for (int i = 0; i < m_size; i++)
    //         {
    //            m_ptr[i]= arr.m_ptr[i];
    //         }
            
    //     }
        
    // }

    friend IntArray& operator=( IntArray src)
    {
        using std::swap;

        swap(*this, src)
        return *this;
    }

 


};
