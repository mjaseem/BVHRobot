#include "bvh_tokens.hpp"

using namespace bvh;

token_map_t token_map_array::token_map[NUM_TOKENS] = {
  {_HIERARCHY ,  "HIERARCHY"},
  {_ROOT      ,  "ROOT"},
  {_OFFSET    ,  "OFFSET"},
  {_CHANNELS  ,  "CHANNELS"},
  {_JOINT     ,  "JOINT"},
  {_ENDSITE   ,  "End Site"},
  {_MOTION    ,  "MOTION"},
  {_FRAMES    ,  "Frames:"},
  {_FRAMETIME ,  "Frame Time:"},
  {_CURLY_BRACE_OPEN  , "{"},
  {_CURLY_BRACE_CLOSE , "}"},
  {_XPOS      ,  "Xposition"},
  {_YPOS      ,  "Yposition"},
  {_ZPOS      ,  "Zposition"},
  {_XROT      ,  "Xrotation"},
  {_YROT      ,  "Yrotation"},
  {_ZROT      ,  "Zrotation"}
};

token_map_array::token_map_array()
{ }

token_map_array::~token_map_array()
{ }

std::string token_map_array::get_strtoken(const int _token)
{
  for(int i=0; i<NUM_TOKENS; i++)
    {
      if (token_map[i].token == _token) return token_map[i].strtoken;
    }
  return std::string("");
}

int token_map_array::get_token(const std::string _strtoken)
{
  for(int i=0; i<NUM_TOKENS; i++)
    {
      if (token_map[i].strtoken == _strtoken) return token_map[i].token;
    }
  return -1;
}

int token_map_array::get_size(void)
{
  return NUM_TOKENS;
}

