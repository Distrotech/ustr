#define USTR_CONF_INCLUDE_CODEONLY_HEADERS 1
#define USTR_CONF_INCLUDE_INTERNAL_HEADERS 1
#include "ustr-conf-debug.h"
#define USTR_CONF_USE_DYNAMIC_CONF USTR_CONF_HAVE_DYNAMIC_CONF
#define USTR_CONF_e_PROTO  extern
#define USTR_CONF_i_PROTO  inline
#define USTR_CONF_E_PROTO  extern
#define USTR_CONF_I_PROTO
#define USTR_CONF_EI_PROTO extern
#define USTR_CONF_II_PROTO inline
#include "ustr-main.h"
