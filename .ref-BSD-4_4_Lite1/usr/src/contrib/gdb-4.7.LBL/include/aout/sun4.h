begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPARC-specific values for a.out files */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|0x2000
end_define

begin_comment
comment|/* 8K.  aka NBPG in<sys/param.h> */
end_comment

begin_comment
comment|/* Note that some SPARCs have 4K pages, some 8K, some others.  */
end_comment

begin_define
define|#
directive|define
name|SEG_SIZE_SPARC
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|SEG_SIZE_SUN3
value|0x20000
end_define

begin_comment
comment|/* Resolution of r/w protection hw */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|PAGE_SIZE
end_define

begin_comment
comment|/* Location 0 is not accessible */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_comment
comment|/* Non-default definitions of the accessor macros... */
end_comment

begin_comment
comment|/* Segment size varies on Sun-3 versus Sun-4.  */
end_comment

begin_define
define|#
directive|define
name|N_SEGSIZE
parameter_list|(
name|x
parameter_list|)
value|(N_MACHTYPE(x) == M_SPARC?	SEG_SIZE_SPARC:	\ 			 N_MACHTYPE(x) == M_68020?	SEG_SIZE_SUN3:	\
comment|/* Guess? */
value|PAGE_SIZE)
end_define

begin_comment
comment|/* Virtual Address of text segment from the a.out file.  For OMAGIC,    (almost always "unlinked .o's" these days), should be zero.    Sun added a kludge so that shared libraries linked ZMAGIC get    an address of zero if a_entry (!!!) is lower than the otherwise    expected text address.  These kludges have gotta go!    For linked files, should reflect reality if we know it.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_MAGIC(x)==OMAGIC? 0 \      : (N_MAGIC(x) == ZMAGIC&& (x).a_entry< TEXT_START_ADDR)? 0 \      : TEXT_START_ADDR+EXEC_BYTES_SIZE)
end_define

end_unit

