begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* malloc.h - Quipu specific mallocing */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/malloc.h,v 7.1 91/02/22 09:25:57 mrose Interim $  *  *   * $Log:	malloc.h,v $  * Revision 7.1  91/02/22  09:25:57  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:57:06  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUIPUMALLOC_
end_ifndef

begin_define
define|#
directive|define
name|_QUIPUMALLOC_
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|mem_heap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|attr_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #define MALLOCSTACK */
end_comment

begin_comment
comment|/* HEAP Selection */
end_comment

begin_comment
comment|/* Two main heaps - general and database.  * Database is split into main critical part,   * and several parts for attribute values.  */
end_comment

begin_define
define|#
directive|define
name|GENERAL_HEAP
value|mem_heap = 0;
end_define

begin_comment
comment|/* general mallocing */
end_comment

begin_define
define|#
directive|define
name|DATABASE_HEAP
value|mem_heap = 1;
end_define

begin_comment
comment|/* critical database structures */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_HEAP
value|{if (mem_heap == 1) mem_heap = 2 + attr_index;}
end_define

begin_comment
comment|/* non critical database structures */
end_comment

begin_define
define|#
directive|define
name|RESTORE_HEAP
value|{if (mem_heap>= 2) mem_heap = 1;}
end_define

begin_define
define|#
directive|define
name|SET_HEAP
parameter_list|(
name|x
parameter_list|)
value|{if (mem_heap == 1) mem_heap = 2 + set_heap (x);}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

