begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)objfmt.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The size of the display.  */
end_comment

begin_define
define|#
directive|define
name|DSPLYSZ
value|20
end_define

begin_comment
comment|/*  *	The structure of the runtime display  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_struct
struct|struct
name|dispsave
block|{
name|char
modifier|*
name|locvars
decl_stmt|;
comment|/* pointer to local variables */
name|struct
name|blockmark
modifier|*
name|stp
decl_stmt|;
comment|/* pointer to local stack frame */
block|}
struct|;
end_struct

begin_comment
comment|/* 	 * The following union allows fast access to 	 * precomputed display entries 	 */
end_comment

begin_union
union|union
name|display
block|{
name|struct
name|dispsave
name|frame
index|[
name|DSPLYSZ
index|]
decl_stmt|;
name|char
modifier|*
name|raw
index|[
literal|2
operator|*
name|DSPLYSZ
index|]
decl_stmt|;
block|}
name|display
union|;
end_union

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/* 	 *	the display is made up of saved AP's and FP's. 	 *	FP's are used to find locals, 	 *	and AP's are used to find parameters. 	 *	FP and AP are untyped pointers, 	 *	but are used throughout as (char *). 	 *	the display is used by adding AP_OFFSET or FP_OFFSET to the  	 *	address of the approriate display entry. 	 */
end_comment

begin_struct
struct|struct
name|dispsave
block|{
name|char
modifier|*
name|savedAP
decl_stmt|;
name|char
modifier|*
name|savedFP
decl_stmt|;
block|}
name|display
index|[
name|DSPLYSZ
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|AP_OFFSET
value|( 0 )
end_define

begin_define
define|#
directive|define
name|FP_OFFSET
value|( sizeof (char *) )
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_comment
comment|/* 	 *	the display is just the saved a6. 	 *	arguments are at positive offsets, 	 *	locals are at negative offsets. 	 *	there are no offsets within the saved display structure. 	 */
end_comment

begin_struct
struct|struct
name|dispsave
block|{
name|char
modifier|*
name|saveda6
decl_stmt|;
block|}
name|display
index|[
name|DSPLYSZ
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|AP_OFFSET
value|(0)
end_define

begin_define
define|#
directive|define
name|FP_OFFSET
value|(0)
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/* 	 *	the display is just the saved FP. 	 *	arguments are at positive offsets, 	 *	locals are at negative offsets. 	 *	there are no offsets within the saved display structure. 	 */
end_comment

begin_struct
struct|struct
name|dispsave
block|{
name|char
modifier|*
name|savedFP
decl_stmt|;
block|}
name|display
index|[
name|DSPLYSZ
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|AP_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|FP_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_comment
comment|/*      *	the structure below describes the block mark used by the architecture.      *	this is the space used by the machine between the arguments and the      *	whatever is used to point to the arguments.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_struct
struct|struct
name|blockmark
block|{
name|char
modifier|*
name|tos
decl_stmt|;
comment|/* pointer to top of stack frame */
name|struct
name|iorec
modifier|*
name|file
decl_stmt|;
comment|/* pointer to active file name */
struct|struct
name|hdr
block|{
name|long
name|framesze
decl_stmt|;
comment|/* number of bytes of local vars */
name|long
name|nargs
decl_stmt|;
comment|/* number of bytes of arguments */
name|long
name|tests
decl_stmt|;
comment|/* TRUE => perform runtime tests */
name|short
name|offset
decl_stmt|;
comment|/* offset of procedure in source file */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of active procedure */
block|}
modifier|*
name|entry
struct|;
name|struct
name|dispsave
name|odisp
decl_stmt|;
comment|/* previous display value for this level */
name|struct
name|dispsave
modifier|*
name|dp
decl_stmt|;
comment|/* pointer to active display entry */
name|char
modifier|*
name|pc
decl_stmt|;
comment|/* previous location counter */
name|long
name|lino
decl_stmt|;
comment|/* previous line number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/* 	 *	since we have the ap pointing to the number of args: 	 */
end_comment

begin_struct
struct|struct
name|blockmark
block|{
name|long
name|nargs
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_comment
comment|/* 	 *	there's the saved pc (from the jsr) 	 *	and the saved a6 (from the link a6). 	 */
end_comment

begin_struct
struct|struct
name|blockmark
block|{
name|char
modifier|*
name|savedpc
decl_stmt|;
name|char
modifier|*
name|saveda6
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/* 	 *	since we have the fp pointing to its predecessor 	 */
end_comment

begin_struct
struct|struct
name|blockmark
block|{
name|long
name|savedfp
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_comment
comment|/*      *	formal routine structure:      */
end_comment

begin_struct
struct|struct
name|formalrtn
block|{
name|long
function_decl|(
modifier|*
name|fentryaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* formal entry point */
name|long
name|fbn
decl_stmt|;
comment|/* block number of function */
name|struct
name|dispsave
name|fdisp
index|[
name|DSPLYSZ
index|]
decl_stmt|;
comment|/* saved at first passing */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ
end_ifndef

begin_decl_stmt
name|struct
name|formalrtn
name|frtn
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FENTRYOFFSET
value|0
end_define

begin_define
define|#
directive|define
name|FBNOFFSET
value|( FENTRYOFFSET + sizeof frtn.fentryaddr )
end_define

begin_define
define|#
directive|define
name|FDISPOFFSET
value|( FBNOFFSET + sizeof frtn.fbn )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_comment
comment|/* 	 *	the creation time, the size and the magic number of the obj file 	 */
end_comment

begin_struct
struct|struct
name|pxhdr
block|{
name|long
name|maketime
decl_stmt|;
name|long
name|objsize
decl_stmt|;
name|long
name|symtabsize
decl_stmt|;
name|short
name|magicnum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	START defines the beginning of the text space.  *	This should be the defined external label "start",  *	however there is no way to access externals from C  *	whose names do not begin with an "_".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|HEADER_BYTES
value|2048
end_define

begin_comment
comment|/* the size of px_header */
end_comment

begin_define
define|#
directive|define
name|START
value|0x0
end_define

begin_comment
comment|/* beginning of text */
end_comment

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|HEADER_BYTES
value|2560
end_define

begin_comment
comment|/* the size of px_header */
end_comment

begin_define
define|#
directive|define
name|START
value|0x0
end_define

begin_comment
comment|/* beginning of text */
end_comment

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_define
define|#
directive|define
name|HEADER_BYTES
value|6092
end_define

begin_comment
comment|/* the size of px_header */
end_comment

begin_define
define|#
directive|define
name|START
value|0x8000
end_define

begin_comment
comment|/* beginning of text */
end_comment

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_define
define|#
directive|define
name|INDX
value|1
end_define

begin_comment
comment|/* amt to shift display index */
end_comment

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_comment
comment|/* 	     *	these are because of varying sizes of pointers 	     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|PTR_AS
value|O_AS2
end_define

begin_define
define|#
directive|define
name|PTR_RV
value|O_RV2
end_define

begin_define
define|#
directive|define
name|PTR_IND
value|O_IND2
end_define

begin_define
define|#
directive|define
name|PTR_CON
value|O_CON2
end_define

begin_define
define|#
directive|define
name|PTR_DUP
value|O_SDUP2
end_define

begin_define
define|#
directive|define
name|CON_INT
value|O_CON2
end_define

begin_define
define|#
directive|define
name|INT_TYP
value|(nl + T2INT)
end_define

begin_define
define|#
directive|define
name|PTR_DCL
value|char *
end_define

begin_define
define|#
directive|define
name|TOOMUCH
value|50000
end_define

begin_define
define|#
directive|define
name|SHORTADDR
value|65536
end_define

begin_define
define|#
directive|define
name|MAXSET
value|65536
end_define

begin_comment
comment|/* maximum set size */
end_comment

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|PTR_AS
value|O_AS4
end_define

begin_define
define|#
directive|define
name|PTR_RV
value|O_RV4
end_define

begin_define
define|#
directive|define
name|PTR_IND
value|O_IND4
end_define

begin_define
define|#
directive|define
name|PTR_CON
value|O_CON4
end_define

begin_define
define|#
directive|define
name|PTR_DUP
value|O_SDUP4
end_define

begin_define
define|#
directive|define
name|CON_INT
value|O_CON24
end_define

begin_define
define|#
directive|define
name|INT_TYP
value|(nl + T4INT)
end_define

begin_define
define|#
directive|define
name|PTR_DCL
value|unsigned long
end_define

begin_comment
comment|/* for pointer variables */
end_comment

begin_define
define|#
directive|define
name|SHORTADDR
value|32768
end_define

begin_comment
comment|/* maximum short address */
end_comment

begin_define
define|#
directive|define
name|TOOMUCH
value|65536
end_define

begin_comment
comment|/* maximum variable size */
end_comment

begin_define
define|#
directive|define
name|MAXSET
value|65536
end_define

begin_comment
comment|/* maximum set size */
end_comment

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_comment
comment|/* 	 * Offsets due to the structure of the runtime stack. 	 * DPOFF1	is the amount of fixed storage in each block allocated 	 * 		as local variables for the runtime system. 	 *		since locals are allocated negative offsets, 	 *		-DPOFF1 is the last used implicit local offset. 	 * DPOFF2	is the size of the block mark. 	 *		since arguments are allocated positive offsets, 	 *		DPOFF2 is the end of the implicit arguments. 	 *		for obj, the first argument has the highest offset 	 *		from the stackpointer.  and the block mark is an 	 *		implicit last parameter. 	 *		for pc, the first argument has the lowest offset 	 *		from the argumentpointer.  and the block mark is an 	 *		implicit first parameter. 	 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|MAGICNUM
value|0403
end_define

begin_comment
comment|/* obj magic number */
end_comment

begin_define
define|#
directive|define
name|DPOFF1
value|0
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|(sizeof (struct blockmark))
end_define

begin_define
define|#
directive|define
name|INPUT_OFF
value|-8
end_define

begin_comment
comment|/* offset of `input' */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|-4
end_define

begin_comment
comment|/* offset of `output' */
end_comment

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|MAGICNUM
value|0404
end_define

begin_define
define|#
directive|define
name|DPOFF1
value|0
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|(sizeof (struct blockmark))
end_define

begin_define
define|#
directive|define
name|INPUT_OFF
value|-2
end_define

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|-4
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|DPOFF1
value|( sizeof (struct rtlocals) )
end_define

begin_define
define|#
directive|define
name|DPOFF2
value|( sizeof (struct blockmark) )
end_define

begin_define
define|#
directive|define
name|INPUT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|OUTPUT_OFF
value|0
end_define

begin_endif
endif|#
directive|endif
endif|PC
end_endif

end_unit

