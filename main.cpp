#include <iostream>
#include "Stack.hpp"

int main(){
    Stack<int> st;

    std::cout << "SIZE: " << st.get_size() << "\n";
    for (int i = 0; i < 14; i++)
        st.push(i);
    
    //Will be printing from 0-13 not 13-0
    for (int &i: st)
        std::cout << "GET! " << i << std::endl;
    
    std::cout << std::endl;

    //To print out just like stack
    for (int i = 0; i < st.get_size(); i++)
        std::cout << "POP! " << st.pop() << std::endl;

    std::cout << "SIZE: " <<st.get_size() << std::endl;
    st.resize(30);
    std::cout << "SIZE: "<<st.get_size() << std::endl;
    
    return 0;

}
