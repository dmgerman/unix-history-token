begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h - compile time configuration parameters */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/config.h,v 7.4 91/02/22 09:25:32 mrose Interim $  *  *  * $Log:	config.h,v $  * Revision 7.4  91/02/22  09:25:32  mrose  * Interim 6.8  *   * Revision 7.3  90/07/09  14:38:20  mrose  * sync  *   * Revision 7.2  90/03/15  11:18:03  mrose  * quipu-sync  *   * Revision 7.1  90/01/11  23:53:17  mrose  * lint  *   * Revision 7.0  89/11/23  21:56:27  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/*   * OPTIONS:-  *  * #define PDU_DUMP  * 		If this is defined, and "dish" is invoke with  *		dish -pdu foobar  *		Then a directory "foobar" will be created, and   *		it will contain logs of all the X500 PDUs sent  *  * #define NO_STATS  * 		If defined, the QUIPU will NOT produce statistical  *		logs of both the DSA and DUA.  *  * #define CHECK_FILE_ATTRIBUTES  * 		If and EDB entry contains a FILE attribute, check that  *		the corresponding file exists  *  * #define QUIPU_MALLOC	  * 		Use a version of malloc optimised for the memory  * 		resident Quipu DSA database.  *  * #define TURBO_DISK  *		Store EDB files in gdbm files instead of plain text files.  *		This makes modifies of entries in large EDB files much  *		faster.  See the ../../quipu/turbo directory for tools to  *		help in converting your EDB files.  *  * #define TURBO_AVL  * 		Use AVL trees instead of linked lists to hold EDBs  *		internally.  Use this instead of TURBO_LOAD to get the  * 		NlogN load time.  May also cut the time to do DN  *		resolution.  *  * #define TURBO_INDEX  *		Enable code to build and search database indexes for  *		selected attributes (see tailor file options optimize_attr,  *		index_subtree, and index_siblings).  TURBO_AVL must also  *		be defined for this to work.  This can cut the search  *		time for very large databases.  *  * #define SOUNDEX_PREFIX  *		Consider soundex prefixes as matches.  For example, make  *		"fred" match "frederick".  #defining this option gives  *		approximate matching behavior the same as in version 6.0.  *  * #define HAVE_PROTECTED  *		If defined, enable use of protectedPassword attribute.  *  * #define COMPAT_6_0  *		Operate in a manner compatible with Quipu-6.0  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPU_CONFIG
end_ifndef

begin_define
define|#
directive|define
name|QUIPU_CONFIG
end_define

begin_define
define|#
directive|define
name|PDU_DUMP
end_define

begin_define
define|#
directive|define
name|USE_BUILTIN_OIDS
end_define

begin_define
define|#
directive|define
name|QUIPU_MALLOC
end_define

begin_define
define|#
directive|define
name|HAVE_PROTECTED
end_define

begin_define
define|#
directive|define
name|SOUNDEX_PREFIX
end_define

begin_define
define|#
directive|define
name|TURBO_AVL
end_define

begin_define
define|#
directive|define
name|TURBO_INDEX
end_define

begin_define
define|#
directive|define
name|COMPAT_6_0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_INDEX
end_ifdef

begin_comment
comment|/* Work around quipu realloc "feature" */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUIPU_MALLOC
end_ifdef

begin_undef
undef|#
directive|undef
name|QUIPU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

