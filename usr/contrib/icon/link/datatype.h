begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Descriptor flags, note that these must match the values in h/rt.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0x80000000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0x40000000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|0x20000000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0x10000000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_define
define|#
directive|define
name|OFFSETMASK
value|0x1fffffff
end_define

begin_comment
comment|/* offset mask for variables */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|x
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|x
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|x
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|x
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_define
define|#
directive|define
name|OFFSETMASK
value|x
end_define

begin_comment
comment|/* offset mask for variables */
end_comment

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0100000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0040000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|0020000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0010000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_define
define|#
directive|define
name|OFFSETMASK
value|0017777
end_define

begin_comment
comment|/* offset mask for variables */
end_comment

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_comment
comment|/*  * Type codes (descriptors and blocks).  */
end_comment

begin_define
define|#
directive|define
name|T_INTEGER
value|1
end_define

begin_comment
comment|/* short integer (not put in heap) */
end_comment

begin_comment
comment|/*  * For 32 bit machines, e.g. the Vax, LONGINT's and INTEGER's are  *  the same.  It would be better to have a generic integer type, and  *  also have LONGINT's and SHORTINT's, but at the current time,  *  LONGINT is used both to refer to integers not representable by  *  a short, and as a generic integer type.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LONGS
end_ifdef

begin_define
define|#
directive|define
name|T_LONGINT
value|2
end_define

begin_comment
comment|/* long integer type */
end_comment

begin_else
else|#
directive|else
else|LONGS
end_else

begin_define
define|#
directive|define
name|T_LONGINT
value|1
end_define

begin_comment
comment|/* long integer type */
end_comment

begin_endif
endif|#
directive|endif
endif|LONGS
end_endif

begin_define
define|#
directive|define
name|T_REAL
value|3
end_define

begin_comment
comment|/* real number */
end_comment

begin_define
define|#
directive|define
name|T_CSET
value|4
end_define

begin_comment
comment|/* cset */
end_comment

begin_define
define|#
directive|define
name|T_FILE
value|5
end_define

begin_comment
comment|/* file block */
end_comment

begin_define
define|#
directive|define
name|T_PROC
value|6
end_define

begin_comment
comment|/* procedure block */
end_comment

begin_define
define|#
directive|define
name|T_LIST
value|7
end_define

begin_comment
comment|/* list header block */
end_comment

begin_define
define|#
directive|define
name|T_TABLE
value|8
end_define

begin_comment
comment|/* table header block */
end_comment

begin_define
define|#
directive|define
name|T_RECORD
value|9
end_define

begin_comment
comment|/* record block */
end_comment

begin_define
define|#
directive|define
name|T_TELEM
value|10
end_define

begin_comment
comment|/* table element block */
end_comment

begin_define
define|#
directive|define
name|T_LELEM
value|11
end_define

begin_comment
comment|/* list element block */
end_comment

begin_define
define|#
directive|define
name|T_TVSUBS
value|12
end_define

begin_comment
comment|/* substring trapped variable */
end_comment

begin_define
define|#
directive|define
name|JUNK_13
value|13
end_define

begin_comment
comment|/* (no longer used) */
end_comment

begin_define
define|#
directive|define
name|T_TVTBL
value|14
end_define

begin_comment
comment|/* table element trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVPOS
value|15
end_define

begin_comment
comment|/*&pos trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVRAND
value|16
end_define

begin_comment
comment|/*&random trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVTRACE
value|17
end_define

begin_comment
comment|/*&trace trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_ESTACK
value|18
end_define

begin_comment
comment|/* expression stack block */
end_comment

begin_define
define|#
directive|define
name|T_EBLOCK
value|19
end_define

begin_comment
comment|/* expression heap block */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_define
define|#
directive|define
name|T_SET
value|20
end_define

begin_comment
comment|/* set header block */
end_comment

begin_define
define|#
directive|define
name|T_SELEM
value|21
end_define

begin_comment
comment|/* set element block */
end_comment

begin_define
define|#
directive|define
name|MAXTYPE
value|21
end_define

begin_comment
comment|/* maximum type number */
end_comment

begin_else
else|#
directive|else
else|SETS
end_else

begin_define
define|#
directive|define
name|MAXTYPE
value|19
end_define

begin_comment
comment|/* maximum type number */
end_comment

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_comment
comment|/*  * Descriptor types and flags.  */
end_comment

begin_define
define|#
directive|define
name|D_VAR
value|(F_VAR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVAR
value|(F_VAR | F_TVAR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_NULL
value|0
end_define

begin_define
define|#
directive|define
name|D_INTEGER
value|(T_INTEGER | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LONGINT
value|(T_LONGINT | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_REAL
value|(T_REAL | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_CSET
value|(T_CSET | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_FILE
value|(T_FILE | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_PROC
value|(T_PROC | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LIST
value|(T_LIST | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TABLE
value|(T_TABLE | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_RECORD
value|(T_RECORD | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TELEM
value|(T_TELEM | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LELEM
value|(T_LELEM | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVSUBS
value|(T_TVSUBS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTBL
value|(T_TVTBL | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVPOS
value|(T_TVPOS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVRAND
value|(T_TVRAND | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTRACE
value|(T_TVTRACE | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_ESTACK
value|(T_ESTACK | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_EBLOCK
value|(T_EBLOCK | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_SET
value|(T_SET | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_SELEM
value|(T_SELEM | F_PTR | F_NQUAL)
end_define

end_unit

