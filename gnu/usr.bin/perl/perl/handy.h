begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: handy.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:06 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: handy.h,v $  * Revision 1.2  1995/05/30 05:03:06  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:36  nate  * PERL!  *  * Revision 4.0.1.4  92/06/08  13:23:17  lwall  * patch20: isascii() may now be supplied by a library routine  * patch20: Perl now distinguishes overlapped copies from non-overlapped  *  * Revision 4.0.1.3  91/11/05  22:54:26  lwall  * patch11: erratum  *  * Revision 4.0.1.2  91/11/05  17:23:38  lwall  * patch11: prepared for ctype implementations that don't define isascii()  *  * Revision 4.0.1.1  91/06/07  11:09:56  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:22:15  lwall  * 4.0 baseline.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|I286
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Null
parameter_list|(
name|type
parameter_list|)
value|((type)NULL)
end_define

begin_define
define|#
directive|define
name|Nullch
value|Null(char*)
end_define

begin_define
define|#
directive|define
name|Nullfp
value|Null(FILE*)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UTS
end_ifdef

begin_define
define|#
directive|define
name|bool
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|ch
parameter_list|)
value|(ch& 037)
end_define

begin_define
define|#
directive|define
name|strNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strLT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)< 0)
end_define

begin_define
define|#
directive|define
name|strLE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)<= 0)
end_define

begin_define
define|#
directive|define
name|strGT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)> 0)
end_define

begin_define
define|#
directive|define
name|strGE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)>= 0)
end_define

begin_define
define|#
directive|define
name|strnNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(strncmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1,s2,l))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CTYPE256
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_ISASCII
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|isALNUM
parameter_list|(
name|c
parameter_list|)
value|(isalpha(c) || isdigit(c) || c == '_')
end_define

begin_define
define|#
directive|define
name|isALPHA
parameter_list|(
name|c
parameter_list|)
value|isalpha(c)
end_define

begin_define
define|#
directive|define
name|isSPACE
parameter_list|(
name|c
parameter_list|)
value|isspace(c)
end_define

begin_define
define|#
directive|define
name|isDIGIT
parameter_list|(
name|c
parameter_list|)
value|isdigit(c)
end_define

begin_define
define|#
directive|define
name|isUPPER
parameter_list|(
name|c
parameter_list|)
value|isupper(c)
end_define

begin_define
define|#
directive|define
name|isLOWER
parameter_list|(
name|c
parameter_list|)
value|islower(c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isALNUM
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& (isalpha(c) || isdigit(c) || c == '_'))
end_define

begin_define
define|#
directive|define
name|isALPHA
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalpha(c))
end_define

begin_define
define|#
directive|define
name|isSPACE
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isspace(c))
end_define

begin_define
define|#
directive|define
name|isDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isdigit(c))
end_define

begin_define
define|#
directive|define
name|isUPPER
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isupper(c))
end_define

begin_define
define|#
directive|define
name|isLOWER
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& islower(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Line numbers are unsigned, 16 bits. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|line_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|NOLINE
value|((line_t)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NOLINE
value|((line_t) 65535)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|LEAKTEST
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|safemalloc
end_ifndef

begin_function_decl
name|char
modifier|*
name|safemalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|saferealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|safefree
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc((MEM_SIZE)((n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safemalloc((MEM_SIZE)((n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc((MEM_SIZE)((n) * sizeof(t)))), \     memzero((char*)(v), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)saferealloc((char*)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Renewc
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)saferealloc((char*)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc(((unsigned long)(n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safemalloc(((unsigned long)(n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc(((unsigned long)(n) * sizeof(t)))), \     memzero((char*)(v), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)saferealloc((char*)(v),((unsigned long)(n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Renewc
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)saferealloc((char*)(v),((unsigned long)(n)*sizeof(t))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|safefree((char*)d)
end_define

begin_define
define|#
directive|define
name|Str_new
parameter_list|(
name|x
parameter_list|,
name|len
parameter_list|)
value|str_new(len)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LEAKTEST */
end_comment

begin_function_decl
name|char
modifier|*
name|safexmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safexrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|safexfree
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safexmalloc(x,(MEM_SIZE)((n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safexmalloc(x,(MEM_SIZE)((n) * sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safexmalloc(x,(MEM_SIZE)((n) * sizeof(t)))), \     memzero((char*)(v), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safexrealloc((char*)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Renewc
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safexrealloc((char*)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|safexfree((char*)d)
end_define

begin_define
define|#
directive|define
name|Str_new
parameter_list|(
name|x
parameter_list|,
name|len
parameter_list|)
value|str_new(x,len)
end_define

begin_define
define|#
directive|define
name|MAXXCOUNT
value|1200
end_define

begin_decl_stmt
name|long
name|xcount
index|[
name|MAXXCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|lastxcount
index|[
name|MAXXCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LEAKTEST */
end_comment

begin_define
define|#
directive|define
name|Move
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memmove((char*)(d),(char*)(s), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memcpy((char*)(d),(char*)(s), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Zero
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memzero((char*)(d), (n) * sizeof(t))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Move
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Zero
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|d = d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRUCTCOPY
end_ifdef

begin_define
define|#
directive|define
name|StructCopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|*((t*)(d)) = *((t*)(s))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|StructCopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|Copy(s,d,1,t)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

