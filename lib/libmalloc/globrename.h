begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: globrename.h,v 1.4 1993/05/23 05:10:52 moraes Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLOBALRENAME_H__
end_ifndef

begin_define
define|#
directive|define
name|__GLOBALRENAME_H__
end_define

begin_comment
comment|/*  *  Renaming all external symbols that are internal to the malloc to be  *  unique within 6 characters for machines whose linkers just can't keep  *  up. We hope the cpp is smart enough - if not, get GNU cccp or the  *  cpp that comes with X Windows Version 11 Release 3.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHORTNAMES
end_ifdef

begin_define
define|#
directive|define
name|_malloc_minchunk
value|__MAL1_minchunk
end_define

begin_define
define|#
directive|define
name|_malloc_rover
value|__MAL2_rover
end_define

begin_define
define|#
directive|define
name|_malloc_hiword
value|__MAL3_hiword
end_define

begin_define
define|#
directive|define
name|_malloc_loword
value|__MAL4_loword
end_define

begin_define
define|#
directive|define
name|_malloc_sbrkunits
value|__MAL5_sbrkunits
end_define

begin_define
define|#
directive|define
name|_malloc_totalavail
value|__MAL6_totalavail
end_define

begin_define
define|#
directive|define
name|_malloc_mem
value|__MAL7_mem
end_define

begin_define
define|#
directive|define
name|_malloc_tracing
value|__MAL8_tracing
end_define

begin_define
define|#
directive|define
name|_malloc_statsfile
value|__MAL9_statsfile
end_define

begin_define
define|#
directive|define
name|_malloc_statsbuf
value|__MALA_statsbuf
end_define

begin_define
define|#
directive|define
name|_malloc_leaktrace
value|__MALB_leaktrace
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROFILESIZES
end_ifdef

begin_define
define|#
directive|define
name|_malloc_scount
value|__MALC_scount
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILESIZES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  *  0 or 1 means checking all pointers before using them. Reasonably  *  thorough.  2 means check the entire heap on every call to  *  malloc/free/realloc/memalign. (the rest call these)  */
end_comment

begin_define
define|#
directive|define
name|_malloc_debugging
value|__MALD_debugging
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|_malloc_version
value|__MALE_version
end_define

begin_define
define|#
directive|define
name|_malloc_memfunc
value|__MALF_memfunc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHORTNAMES */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLOBALRENAME_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

