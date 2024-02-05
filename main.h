#include <cassert>
#include <iostream>
template <typename T, size_t N>
class CirkelBuffer
{
    T data_[N];       // array to store the elementsd of the circular buffer
    size_t head_ = 0; // index point of the head/front of the buffer
    size_t tail_ = 0; // index pointing to the next obtainble place in the back/tail of the buffer
    size_t count_ = 0;

private:
    CirkelBuffer(const CirkelBuffer &) = delete;            // Makes the class uncopyable
    CirkelBuffer &operator=(const CirkelBuffer &) = delete; // Makes the class unassignable

    // function to calculate the next index in the buffer.
    size_t NextIndex(size_t current) const
    {
        return (current + 1) % N;
    }

public: // constructor and destructor
    CirkelBuffer() {}

    ~CirkelBuffer() {}

    void Clear()
    {
        head_ = 0;
        tail_ = 0;
        count_ = 0;
    }

    T Read()
    {
        // check if there element in the buffer
        if (count_ > 0)
        {
            // read value to the present head index
            T val = data_[head_];
            head_ = NextIndex(head_);
            --count_;
            // returns the value that was read from the buffer.
            return val;
        }
        else
        {

            return T();
        }
    }

    // Write data to the buffer
    void Write(const T &val)
    {
        // count_ == N checks if the buffer is full
        if (count_ == N)
        {
            // Buffer is full, move head to overwrite oldest element
            head_ = NextIndex(head_);
        }

        // write the new value to the present tail index. increment to the next free position.
        data_[tail_] = val;
        tail_ = NextIndex(tail_);

        // Increment count only if the buffer was not full
        if (count_ < N)
        {
            ++count_;
        }
    }
    // Return the present number of elements in the buffer
    size_t Size() const
    {
        return count_;
    }

    // True if the buffer is full
    bool IsFull() const
    {
        return count_ == N;
    }
    // Overloaded output stream operator printing the  CirkelBuffer.
    friend std::ostream &operator<<(std::ostream &os, const CirkelBuffer &buffer)
    {
        
        if (buffer.Size() > 0)
        {
            for (size_t i = 0; i < buffer.Size(); ++i)
            { 
                
                /* buffer.head +i = calculate index . And then the index go back to the start 
                after hitting the tail. %N calculate reminder */
                 os << buffer.data_[(buffer.head_ + i) % N] << " ";
            }
        }
        else
        { 
            //Prints a message that the buffer is empty.
            os << " Buffer is empty!";
        }
        //Returns the output stream
        return os;
    }
};
