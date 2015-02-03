/*!
  \file bvh_tokens.hpp
  \brief This file contains the list of recognized tokens for a valid bvh file
*/
#ifndef _BVH_TOKENS_HPP_
#define _BVH_TOKENS_HPP_ 

#include <string>

//! The namespace for all classes that form the libBVH library
namespace bvh
{
  //!Total number of recognized tokens
#define NUM_TOKENS 17
  //@{
  //! Token code
#define _HIERARCHY 0
#define _ROOT      1
#define _OFFSET    2
#define _CHANNELS  3
#define _JOINT     4
#define _ENDSITE   5

#define _MOTION    6
#define _FRAMES    7
#define _FRAMETIME 8
      
#define _CURLY_BRACE_OPEN  9
#define _CURLY_BRACE_CLOSE 10

#define _XPOS 11
#define _YPOS 12
#define _ZPOS 13
#define _XROT 14
#define _YROT 15
#define _ZROT 16
//@}
  //! The token map datatype
  /*! The token_map_t datatype is for storing a valid token (strtoken)
   *  along with its token code (token).
   */
  struct token_map_t
  {
    //! Token code
    int token;
    //! Token
    std::string strtoken;
  };
  
  //! The token map array data structure 
  /*! The token map array contains all the valid tokens of the bvh 
   *  file format mapped to their corresponding codes and functions 
   *  to access them.
   */
  class token_map_array
  {
  protected:
    //! The actual token map.
    /*! This array is statically initialized since this class
     *  is to be instantiated only once. If done more number of 
     *  times each will share the same token toke map
     */
    static token_map_t token_map[NUM_TOKENS];
    
  public:
    //! Dummy constructor
    token_map_array();
    //! Dummy destructor
    ~token_map_array();
    
    //! Returns the token string given the token code
    static std::string get_strtoken(const int _token);
    //! Returns the token code given the token string
    static int get_token(const std::string _strtoken);
    //! Returns size of the array
    static int get_size(void);
  };
}

#endif
