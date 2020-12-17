
/*  Scan the listings in Chapter 2. Which methods could be marked const?
 *  Where could you use auto?
 */

/*  COMMENT
 *
 *  In Listing 2-20, we can mark the member function
 *  int get_year() as const because we know it doesn't
 *  change the current state of the object and also
 *  it's a getter function which only returns.
 * 
 *  As for auto, we CAN find all the explicit types in every Listing
 *  and swap them with the keyword auto; however, that's not the ideal
 *  in my opinion. For simple types such as int, double, char, etc, we
 *  can write those explicit, but for more complicated types such as
 *  in Listing 2-1: 
 *  unsigned short a = 0b10101010
 *  unsigned long long d = 0xFFFFFFFFFFFFFFFF; 
 *  we can use auto type deduction to save us the pain
 *  of typing it. It hides some incredibly long and ugly
 *  typenames.
 */