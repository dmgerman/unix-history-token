begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	config.h	4.4	90/02/21	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_
end_define

begin_comment
comment|/*  * Compiler configuration definitions.  */
end_comment

begin_comment
comment|/*  * These flags control global compiler operation.  */
end_comment

begin_define
define|#
directive|define
name|BUFSTDERR
value|1
end_define

begin_comment
comment|/* buffer output to stderr */
end_comment

begin_define
define|#
directive|define
name|STDPRTREE
value|1
end_define

begin_comment
comment|/* means include prtree */
end_comment

begin_define
define|#
directive|define
name|NESTCALLS
value|1
end_define

begin_comment
comment|/* disallow two concurrent store()'s */
end_comment

begin_define
define|#
directive|define
name|FLEXNAMES
value|1
end_define

begin_comment
comment|/* arbitrary length identifiers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FORT
end_ifdef

begin_define
define|#
directive|define
name|NOMAIN
value|1
end_define

begin_comment
comment|/* use f1 main routine */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Table sizes.  */
end_comment

begin_define
define|#
directive|define
name|TREESZ
value|1000
end_define

begin_comment
comment|/* parse tree table size */
end_comment

begin_define
define|#
directive|define
name|BCSZ
value|100
end_define

begin_comment
comment|/* break/continue table size */
end_comment

begin_define
define|#
directive|define
name|SYMTSZ
value|4000
end_define

begin_comment
comment|/* symbol table size */
end_comment

begin_define
define|#
directive|define
name|DIMTABSZ
value|5000
end_define

begin_comment
comment|/* dimension/size table size */
end_comment

begin_define
define|#
directive|define
name|PARAMSZ
value|300
end_define

begin_comment
comment|/* parameter stack size */
end_comment

begin_define
define|#
directive|define
name|SWITSZ
value|500
end_define

begin_comment
comment|/* switch table size */
end_comment

begin_define
define|#
directive|define
name|DELAYS
value|20
end_define

begin_comment
comment|/* delayed evaluation table size */
end_comment

begin_define
define|#
directive|define
name|NRECUR
value|(10*TREESZ)
end_define

begin_comment
comment|/* maximum eval recursion depth */
end_comment

begin_define
define|#
directive|define
name|MAXSCOPES
value|(SYMTSZ/30)
end_define

begin_comment
comment|/* maximum active scopes */
end_comment

begin_comment
comment|/* in case anyone still uses fixed length names */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_define
define|#
directive|define
name|NCHNAM
value|8
end_define

begin_comment
comment|/* significant chars of identifier */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

