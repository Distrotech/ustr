/* Copyright (c) 2007 James Antill -- See LICENSE file for terms. */
#ifndef USTR_UTF8_H
#define USTR_UTF8_H 1

#ifndef USTR_MAIN_H
#error " You should have already included ustr-main.h, or just include ustr.h."
#endif

USTR_CONF_EI_PROTO
int ustr_utf8_valid(const struct Ustr *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();
USTR_CONF_E_PROTO
size_t ustr_utf8_len(const struct Ustr *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();
USTR_CONF_E_PROTO
ssize_t ustr_utf8_width(const struct Ustr *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();

USTR_CONF_EI_PROTO
int ustrp_utf8_valid(const struct Ustrp *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();
USTR_CONF_EI_PROTO
size_t ustrp_utf8_len(const struct Ustrp *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();
USTR_CONF_EI_PROTO
ssize_t ustrp_utf8_width(const struct Ustrp *)
    USTR__COMPILE_ATTR_WARN_UNUSED_RET() USTR__COMPILE_ATTR_NONNULL_A();


#if USTR_CONF_INCLUDE_INTERNAL_HEADERS
# include "ustr-utf8-internal.h"
#endif

#if USTR_CONF_INCLUDE_CODEONLY_HEADERS
# include "ustr-utf8-code.h"
#endif

USTR_CONF_II_PROTO
int ustr_utf8_valid(const struct Ustr *s1)
{ return (!ustr_len(s1) || ustr_utf8_len(s1)); }

USTR_CONF_II_PROTO
int ustrp_utf8_valid(const struct Ustrp *s1)
{ return (ustr_utf8_valid(&s1->s)); }
USTR_CONF_II_PROTO
size_t ustrp_utf8_len(const struct Ustrp *s1)
{ return (ustr_utf8_len(&s1->s)); }
USTR_CONF_II_PROTO
ssize_t ustrp_utf8_width(const struct Ustrp *s1)
{ return (ustr_utf8_width(&s1->s)); }


#endif