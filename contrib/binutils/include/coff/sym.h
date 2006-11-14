begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations of internal format of MIPS ECOFF symbols.    Originally contributed by MIPS Computer Systems and Third Eye Software.    Changes contributed by Cygnus Support are in the public domain.       This file is just aggregated with the files that make up the GNU    release; it is not considered part of GAS, GDB, or other GNU    programs.  */
end_comment

begin_comment
comment|/*  * |-----------------------------------------------------------|  * | Copyright (c) 1992, 1991, 1990 MIPS Computer Systems, Inc.|  * | MIPS Computer Systems, Inc. grants reproduction and use   |  * | rights to all parties, PROVIDED that this comment is      |  * | maintained in the copy.                                   |  * |-----------------------------------------------------------|  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYM_H
end_ifndef

begin_define
define|#
directive|define
name|_SYM_H
end_define

begin_comment
comment|/* (C) Copyright 1984 by Third Eye Software, Inc.  *  * Third Eye Software, Inc. grants reproduction and use rights to  * all parties, PROVIDED that this comment is maintained in the copy.  *  * Third Eye makes no claims about the applicability of this  * symbol table to a particular use.  */
end_comment

begin_comment
comment|/*   * This file contains the definition of the Third Eye Symbol Table.  *  * Symbols are assumed to be in 'encounter order' - i.e. the order that  * the things they represent were encountered by the compiler/assembler/loader.  * EXCEPT for globals!	These are assumed to be bunched together,  * probably right after the last 'normal' symbol.  Globals ARE sorted  * in ascending order.  *  * -----------------------------------------------------------------------  * A brief word about Third Eye naming/use conventions:  *  * All arrays and index's are 0 based.  * All "ifooMax" values are the highest legal value PLUS ONE. This makes  * them good for allocating arrays, etc. All checks are "ifoo< ifooMax".  *  * "isym"	Index into the SYMbol table.  * "ipd"	Index into the Procedure Descriptor array.  * "ifd"	Index into the File Descriptor array.  * "iss"	Index into String Space.  * "cb"		Count of Bytes.  * "rgPd"	array whose domain is "0..ipdMax-1" and RanGe is PDR.  * "rgFd"	array whose domain is "0..ifdMax-1" and RanGe is FDR.  */
end_comment

begin_comment
comment|/*   * Symbolic Header (HDR) structure.  * As long as all the pointers are set correctly,  * we don't care WHAT order the various sections come out in!  *  * A file produced solely for the use of CDB will probably NOT have  * any instructions or data areas in it, as these are available  * in the original.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|magic
decl_stmt|;
comment|/* to verify validity of the table */
name|short
name|vstamp
decl_stmt|;
comment|/* version stamp */
name|long
name|ilineMax
decl_stmt|;
comment|/* number of line number entries */
name|bfd_vma
name|cbLine
decl_stmt|;
comment|/* number of bytes for line number entries */
name|bfd_vma
name|cbLineOffset
decl_stmt|;
comment|/* offset to start of line number entries*/
name|long
name|idnMax
decl_stmt|;
comment|/* max index into dense number table */
name|bfd_vma
name|cbDnOffset
decl_stmt|;
comment|/* offset to start dense number table */
name|long
name|ipdMax
decl_stmt|;
comment|/* number of procedures */
name|bfd_vma
name|cbPdOffset
decl_stmt|;
comment|/* offset to procedure descriptor table */
name|long
name|isymMax
decl_stmt|;
comment|/* number of local symbols */
name|bfd_vma
name|cbSymOffset
decl_stmt|;
comment|/* offset to start of local symbols*/
name|long
name|ioptMax
decl_stmt|;
comment|/* max index into optimization symbol entries */
name|bfd_vma
name|cbOptOffset
decl_stmt|;
comment|/* offset to optimization symbol entries */
name|long
name|iauxMax
decl_stmt|;
comment|/* number of auxillary symbol entries */
name|bfd_vma
name|cbAuxOffset
decl_stmt|;
comment|/* offset to start of auxillary symbol entries*/
name|long
name|issMax
decl_stmt|;
comment|/* max index into local strings */
name|bfd_vma
name|cbSsOffset
decl_stmt|;
comment|/* offset to start of local strings */
name|long
name|issExtMax
decl_stmt|;
comment|/* max index into external strings */
name|bfd_vma
name|cbSsExtOffset
decl_stmt|;
comment|/* offset to start of external strings */
name|long
name|ifdMax
decl_stmt|;
comment|/* number of file descriptor entries */
name|bfd_vma
name|cbFdOffset
decl_stmt|;
comment|/* offset to file descriptor table */
name|long
name|crfd
decl_stmt|;
comment|/* number of relative file descriptor entries */
name|bfd_vma
name|cbRfdOffset
decl_stmt|;
comment|/* offset to relative file descriptor table */
name|long
name|iextMax
decl_stmt|;
comment|/* max index into external symbols */
name|bfd_vma
name|cbExtOffset
decl_stmt|;
comment|/* offset to start of external symbol entries*/
comment|/* If you add machine dependent fields, add them here */
block|}
name|HDRR
operator|,
typedef|*
name|pHDRR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbHDRR
value|sizeof(HDRR)
end_define

begin_define
define|#
directive|define
name|hdrNil
value|((pHDRR)0)
end_define

begin_comment
comment|/*  * The FDR and PDR structures speed mapping of address<-> name.  * They are sorted in ascending memory order and are kept in  * memory by CDB at runtime.  */
end_comment

begin_comment
comment|/*   * File Descriptor  *  * There is one of these for EVERY FILE, whether compiled with  * full debugging symbols or not.  The name of a file should be  * the path name given to the compiler.	 This allows the user  * to simply specify the names of the directories where the COMPILES  * were done, and we will be able to find their files.  * A field whose comment starts with "R - " indicates that it will be  * setup at runtime.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fdr
block|{
name|bfd_vma
name|adr
decl_stmt|;
comment|/* memory address of beginning of file */
name|long
name|rss
decl_stmt|;
comment|/* file name (of source, if known) */
name|long
name|issBase
decl_stmt|;
comment|/* file's string space */
name|bfd_vma
name|cbSs
decl_stmt|;
comment|/* number of bytes in the ss */
name|long
name|isymBase
decl_stmt|;
comment|/* beginning of symbols */
name|long
name|csym
decl_stmt|;
comment|/* count file's of symbols */
name|long
name|ilineBase
decl_stmt|;
comment|/* file's line symbols */
name|long
name|cline
decl_stmt|;
comment|/* count of file's line symbols */
name|long
name|ioptBase
decl_stmt|;
comment|/* file's optimization entries */
name|long
name|copt
decl_stmt|;
comment|/* count of file's optimization entries */
name|unsigned
name|short
name|ipdFirst
decl_stmt|;
comment|/* start of procedures for this file */
name|short
name|cpd
decl_stmt|;
comment|/* count of procedures for this file */
name|long
name|iauxBase
decl_stmt|;
comment|/* file's auxiliary entries */
name|long
name|caux
decl_stmt|;
comment|/* count of file's auxiliary entries */
name|long
name|rfdBase
decl_stmt|;
comment|/* index into the file indirect table */
name|long
name|crfd
decl_stmt|;
comment|/* count file indirect entries */
name|unsigned
name|lang
range|:
literal|5
decl_stmt|;
comment|/* language for this file */
name|unsigned
name|fMerge
range|:
literal|1
decl_stmt|;
comment|/* whether this file can be merged */
name|unsigned
name|fReadin
range|:
literal|1
decl_stmt|;
comment|/* true if it was read in (not just created) */
name|unsigned
name|fBigendian
range|:
literal|1
decl_stmt|;
comment|/* if set, was compiled on big endian machine */
comment|/*	aux's will be in compile host's sex */
name|unsigned
name|glevel
range|:
literal|2
decl_stmt|;
comment|/* level this file was compiled with */
name|unsigned
name|reserved
range|:
literal|22
decl_stmt|;
comment|/* reserved for future use */
name|bfd_vma
name|cbLineOffset
decl_stmt|;
comment|/* byte offset from header for this file ln's */
name|bfd_vma
name|cbLine
decl_stmt|;
comment|/* size of lines for this file */
block|}
name|FDR
operator|,
typedef|*
name|pFDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbFDR
value|sizeof(FDR)
end_define

begin_define
define|#
directive|define
name|fdNil
value|((pFDR)0)
end_define

begin_define
define|#
directive|define
name|ifdNil
value|-1
end_define

begin_define
define|#
directive|define
name|ifdTemp
value|0
end_define

begin_define
define|#
directive|define
name|ilnNil
value|-1
end_define

begin_comment
comment|/*   * Procedure Descriptor  *  * There is one of these for EVERY TEXT LABEL.  * If a procedure is in a file with full symbols, then isym  * will point to the PROC symbols, else it will point to the  * global symbol for the label.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pdr
block|{
name|bfd_vma
name|adr
decl_stmt|;
comment|/* memory address of start of procedure */
name|long
name|isym
decl_stmt|;
comment|/* start of local symbol entries */
name|long
name|iline
decl_stmt|;
comment|/* start of line number entries*/
name|long
name|regmask
decl_stmt|;
comment|/* save register mask */
name|long
name|regoffset
decl_stmt|;
comment|/* save register offset */
name|long
name|iopt
decl_stmt|;
comment|/* start of optimization symbol entries*/
name|long
name|fregmask
decl_stmt|;
comment|/* save floating point register mask */
name|long
name|fregoffset
decl_stmt|;
comment|/* save floating point register offset */
name|long
name|frameoffset
decl_stmt|;
comment|/* frame size */
name|short
name|framereg
decl_stmt|;
comment|/* frame pointer register */
name|short
name|pcreg
decl_stmt|;
comment|/* offset or reg of return pc */
name|long
name|lnLow
decl_stmt|;
comment|/* lowest line in the procedure */
name|long
name|lnHigh
decl_stmt|;
comment|/* highest line in the procedure */
name|bfd_vma
name|cbLineOffset
decl_stmt|;
comment|/* byte offset for this procedure from the fd base */
comment|/* These fields are new for 64 bit ECOFF.  */
name|unsigned
name|gp_prologue
range|:
literal|8
decl_stmt|;
comment|/* byte size of GP prologue */
name|unsigned
name|gp_used
range|:
literal|1
decl_stmt|;
comment|/* true if the procedure uses GP */
name|unsigned
name|reg_frame
range|:
literal|1
decl_stmt|;
comment|/* true if register frame procedure */
name|unsigned
name|prof
range|:
literal|1
decl_stmt|;
comment|/* true if compiled with -pg */
name|unsigned
name|reserved
range|:
literal|13
decl_stmt|;
comment|/* reserved: must be zero */
name|unsigned
name|localoff
range|:
literal|8
decl_stmt|;
comment|/* offset of local variables from vfp */
block|}
name|PDR
operator|,
typedef|*
name|pPDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbPDR
value|sizeof(PDR)
end_define

begin_define
define|#
directive|define
name|pdNil
value|((pPDR) 0)
end_define

begin_define
define|#
directive|define
name|ipdNil
value|-1
end_define

begin_comment
comment|/*  * The structure of the runtime procedure descriptor created by the loader  * for use by the static exception system.  */
end_comment

begin_comment
comment|/*  * If 0'd out because exception_info chokes Visual C++ and because there  * don't seem to be any references to this structure elsewhere in gdb.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|typedef struct runtime_pdr { 	bfd_vma	adr;
comment|/* memory address of start of procedure */
end_comment

begin_comment
unit|long	regmask;
comment|/* save register mask */
end_comment

begin_comment
unit|long	regoffset;
comment|/* save register offset */
end_comment

begin_comment
unit|long	fregmask;
comment|/* save floating point register mask */
end_comment

begin_comment
unit|long	fregoffset;
comment|/* save floating point register offset */
end_comment

begin_comment
unit|long	frameoffset;
comment|/* frame size */
end_comment

begin_comment
unit|short	framereg;
comment|/* frame pointer register */
end_comment

begin_comment
unit|short	pcreg;
comment|/* offset or reg of return pc */
end_comment

begin_comment
unit|long	irpss;
comment|/* index into the runtime string table */
end_comment

begin_comment
unit|long	reserved; 	struct exception_info *exception_info;
comment|/* pointer to exception array */
end_comment

begin_define
unit|} RPDR, *pRPDR;
define|#
directive|define
name|cbRPDR
value|sizeof(RPDR)
end_define

begin_define
define|#
directive|define
name|rpdNil
value|((pRPDR) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Line Numbers  *  * Line Numbers are segregated from the normal symbols because they  * are [1] smaller , [2] are of no interest to your  * average loader, and [3] are never needed in the middle of normal  * scanning and therefore slow things down.  *  * By definition, the first LINER for any given procedure will have  * the first line of a procedure and represent the first address.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|LINER
typedef|,
modifier|*
name|pLINER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lineNil
value|((pLINER)0)
end_define

begin_define
define|#
directive|define
name|cbLINER
value|sizeof(LINER)
end_define

begin_define
define|#
directive|define
name|ilineNil
value|-1
end_define

begin_comment
comment|/*  * The Symbol Structure		(GFW, to those who Know!)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|iss
decl_stmt|;
comment|/* index into String Space of name */
name|bfd_vma
name|value
decl_stmt|;
comment|/* value of symbol */
name|unsigned
name|st
range|:
literal|6
decl_stmt|;
comment|/* symbol type */
name|unsigned
name|sc
range|:
literal|5
decl_stmt|;
comment|/* storage class - text, data, etc */
name|unsigned
name|reserved
range|:
literal|1
decl_stmt|;
comment|/* reserved */
name|unsigned
name|index
range|:
literal|20
decl_stmt|;
comment|/* index into sym/aux table */
block|}
name|SYMR
operator|,
typedef|*
name|pSYMR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|symNil
value|((pSYMR)0)
end_define

begin_define
define|#
directive|define
name|cbSYMR
value|sizeof(SYMR)
end_define

begin_define
define|#
directive|define
name|isymNil
value|-1
end_define

begin_define
define|#
directive|define
name|indexNil
value|0xfffff
end_define

begin_define
define|#
directive|define
name|issNil
value|-1
end_define

begin_define
define|#
directive|define
name|issNull
value|0
end_define

begin_comment
comment|/* The following converts a memory resident string to an iss.  * This hack is recognized in SbFIss, in sym.c of the debugger.  */
end_comment

begin_define
define|#
directive|define
name|IssFSb
parameter_list|(
name|sb
parameter_list|)
value|(0x80000000 | ((unsigned long)(sb)))
end_define

begin_comment
comment|/* E X T E R N A L   S Y M B O L  R E C O R D  *  *	Same as the SYMR except it contains file context to determine where  *	the index is.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ecoff_extr
block|{
name|unsigned
name|jmptbl
range|:
literal|1
decl_stmt|;
comment|/* symbol is a jump table entry for shlibs */
name|unsigned
name|cobol_main
range|:
literal|1
decl_stmt|;
comment|/* symbol is a cobol main procedure */
name|unsigned
name|weakext
range|:
literal|1
decl_stmt|;
comment|/* symbol is weak external */
name|unsigned
name|reserved
range|:
literal|13
decl_stmt|;
comment|/* reserved for future use */
name|int
name|ifd
decl_stmt|;
comment|/* where the iss and index fields point into */
name|SYMR
name|asym
decl_stmt|;
comment|/* symbol for the external */
block|}
name|EXTR
operator|,
typedef|*
name|pEXTR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|extNil
value|((pEXTR)0)
end_define

begin_define
define|#
directive|define
name|cbEXTR
value|sizeof(EXTR)
end_define

begin_comment
comment|/* A U X I L L A R Y   T Y P E	 I N F O R M A T I O N */
end_comment

begin_comment
comment|/*  * Type Information Record  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|fBitfield
range|:
literal|1
decl_stmt|;
comment|/* set if bit width is specified */
name|unsigned
name|continued
range|:
literal|1
decl_stmt|;
comment|/* indicates additional TQ info in next AUX */
name|unsigned
name|bt
range|:
literal|6
decl_stmt|;
comment|/* basic type */
name|unsigned
name|tq4
range|:
literal|4
decl_stmt|;
name|unsigned
name|tq5
range|:
literal|4
decl_stmt|;
comment|/* ---- 16 bit boundary ---- */
name|unsigned
name|tq0
range|:
literal|4
decl_stmt|;
name|unsigned
name|tq1
range|:
literal|4
decl_stmt|;
comment|/* 6 type qualifiers - tqPtr, etc. */
name|unsigned
name|tq2
range|:
literal|4
decl_stmt|;
name|unsigned
name|tq3
range|:
literal|4
decl_stmt|;
block|}
name|TIR
operator|,
typedef|*
name|pTIR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbTIR
value|sizeof(TIR)
end_define

begin_define
define|#
directive|define
name|tiNil
value|((pTIR)0)
end_define

begin_define
define|#
directive|define
name|itqMax
value|6
end_define

begin_comment
comment|/*  * Relative symbol record  *  * If the rfd field is 4095, the index field indexes into the global symbol  *	table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|rfd
range|:
literal|12
decl_stmt|;
comment|/* index into the file indirect table */
name|unsigned
name|index
range|:
literal|20
decl_stmt|;
comment|/* index int sym/aux/iss tables */
block|}
name|RNDXR
operator|,
typedef|*
name|pRNDXR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbRNDXR
value|sizeof(RNDXR)
end_define

begin_define
define|#
directive|define
name|rndxNil
value|((pRNDXR)0)
end_define

begin_comment
comment|/* dense numbers or sometimes called block numbers are stored in this type,  *	a rfd of 0xffffffff is an index into the global table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|rfd
decl_stmt|;
comment|/* index into the file table */
name|unsigned
name|long
name|index
decl_stmt|;
comment|/* index int sym/aux/iss tables */
block|}
name|DNR
operator|,
typedef|*
name|pDNR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbDNR
value|sizeof(DNR)
end_define

begin_define
define|#
directive|define
name|dnNil
value|((pDNR)0)
end_define

begin_comment
comment|/*  * Auxillary information occurs only if needed.  * It ALWAYS occurs in this order when present.  	    isymMac		used by stProc only 	    TIR			type info 	    TIR			additional TQ info (if first TIR was not enough) 	    rndx		if (bt == btStruct,btUnion,btEnum,btSet,btRange, 				    btTypedef): 				    rsym.index == iaux for btSet or btRange 				    else rsym.index == isym 	    dimLow		btRange, btSet 	    dimMac		btRange, btSet 	    rndx0		As many as there are tq arrays 	    dimLow0 	    dimHigh0 	    ... 	    rndxMax-1 	    dimLowMax-1 	    dimHighMax-1 	    width in bits	if (bit field), width in bits.  */
end_comment

begin_define
define|#
directive|define
name|cAuxMax
value|(6 + (idimMax*3))
end_define

begin_comment
comment|/* a union of all possible info in the AUX universe */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TIR
name|ti
decl_stmt|;
comment|/* type information record */
name|RNDXR
name|rndx
decl_stmt|;
comment|/* relative index into symbol table */
name|long
name|dnLow
decl_stmt|;
comment|/* low dimension */
name|long
name|dnHigh
decl_stmt|;
comment|/* high dimension */
name|long
name|isym
decl_stmt|;
comment|/* symbol table index (end of proc) */
name|long
name|iss
decl_stmt|;
comment|/* index into string space (not used) */
name|long
name|width
decl_stmt|;
comment|/* width for non-default sized struc fields */
name|long
name|count
decl_stmt|;
comment|/* count of ranges for variant arm */
block|}
name|AUXU
operator|,
typedef|*
name|pAUXU
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbAUXU
value|sizeof(AUXU)
end_define

begin_define
define|#
directive|define
name|auxNil
value|((pAUXU)0)
end_define

begin_define
define|#
directive|define
name|iauxNil
value|-1
end_define

begin_comment
comment|/*  * Optimization symbols  *  * Optimization symbols contain some overlap information with the normal  * symbol table. In particular, the proc information  * is somewhat redundant but necessary to easily find the other information  * present.   *  * All of the offsets are relative to the beginning of the last otProc  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|ot
range|:
literal|8
decl_stmt|;
comment|/* optimization type */
name|unsigned
name|value
range|:
literal|24
decl_stmt|;
comment|/* address where we are moving it to */
name|RNDXR
name|rndx
decl_stmt|;
comment|/* points to a symbol or opt entry */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* relative offset this occured */
block|}
name|OPTR
operator|,
typedef|*
name|pOPTR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|optNil
value|((pOPTR) 0)
end_define

begin_define
define|#
directive|define
name|cbOPTR
value|sizeof(OPTR)
end_define

begin_define
define|#
directive|define
name|ioptNil
value|-1
end_define

begin_comment
comment|/*  * File Indirect  *  * When a symbol is referenced across files the following procedure is used:  *	1) use the file index to get the File indirect entry.  *	2) use the file indirect entry to get the File descriptor.  *	3) add the sym index to the base of that file's sym table  *  */
end_comment

begin_typedef
typedef|typedef
name|long
name|RFDT
typedef|,
modifier|*
name|pRFDT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbRFDT
value|sizeof(RFDT)
end_define

begin_define
define|#
directive|define
name|rfdNil
value|-1
end_define

begin_comment
comment|/*  * The file indirect table in the mips loader is known as an array of FITs.  * This is done to keep the code in the loader readable in the area where  * these tables are merged.  Note this is only a name change.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|FIT
typedef|,
modifier|*
name|pFIT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cbFIT
value|sizeof(FIT)
end_define

begin_define
define|#
directive|define
name|ifiNil
value|-1
end_define

begin_define
define|#
directive|define
name|fiNil
value|((pFIT) 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LANGUAGE_PASCAL
end_ifdef

begin_define
define|#
directive|define
name|ifdNil
value|-1
end_define

begin_define
define|#
directive|define
name|ilnNil
value|-1
end_define

begin_define
define|#
directive|define
name|ipdNil
value|-1
end_define

begin_define
define|#
directive|define
name|ilineNil
value|-1
end_define

begin_define
define|#
directive|define
name|isymNil
value|-1
end_define

begin_define
define|#
directive|define
name|indexNil
value|16#fffff
end_define

begin_define
define|#
directive|define
name|issNil
value|-1
end_define

begin_define
define|#
directive|define
name|issNull
value|0
end_define

begin_define
define|#
directive|define
name|itqMax
value|6
end_define

begin_define
define|#
directive|define
name|iauxNil
value|-1
end_define

begin_define
define|#
directive|define
name|ioptNil
value|-1
end_define

begin_define
define|#
directive|define
name|rfdNil
value|-1
end_define

begin_define
define|#
directive|define
name|ifiNil
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LANGUAGE_PASCAL */
end_comment

begin_comment
comment|/* Dense numbers  *  * Rather than use file index, symbol index pairs to represent symbols  *	and globals, we use dense number so that they can be easily embeded  *	in intermediate code and the programs that process them can  *	use direct access tabls instead of hash table (which would be  *	necesary otherwise because of the sparse name space caused by  *	file index, symbol index pairs. Dense number are represented  *	by RNDXRs.  */
end_comment

begin_comment
comment|/*  * The following table defines the meaning of each SYM field as  * a function of the "st". (scD/B == scData OR scBss)  *  * Note: the value "isymMac" is used by symbols that have the concept  * of enclosing a block of related information.	 This value is the  * isym of the first symbol AFTER the end associated with the primary  * symbol. For example if a procedure was at isym==90 and had an  * isymMac==155, the associated end would be at isym==154, and the  * symbol at 155 would probably (although not necessarily) be the  * symbol for the next procedure.  This allows rapid skipping over  * internal information of various sorts. "stEnd"s ALWAYS have the  * isym of the primary symbol that started the block.  *   ST		SC	VALUE		INDEX --------	------	--------	------ stFile		scText	address		isymMac stLabel		scText	address		--- stGlobal	scD/B	address		iaux stStatic	scD/B	address		iaux stParam		scAbs	offset		iaux stLocal		scAbs	offset		iaux stProc		scText	address		iaux	(isymMac is first AUX) stStaticProc	scText	address		iaux	(isymMac is first AUX)  stMember	scNil	ordinal		---	(if member of enum) 	(mipsread thinks the case below has a bit, not byte, offset.) stMember	scNil	byte offset	iaux	(if member of struct/union) stMember	scBits	bit offset	iaux	(bit field spec)  stBlock		scText	address		isymMac (text block) 	(the code seems to think that rather than scNil, we see scInfo for 	 the two cases below.) stBlock		scNil	cb		isymMac (struct/union member define) stBlock		scNil	cMembers	isymMac (enum member define)  	(New types added by SGI to simplify things:) stStruct	scInfo	cb		isymMac (struct type define) stUnion		scInfo	cb		isymMac (union  type define) stEnum		scInfo	cMembers	isymMac (enum   type define)  stEnd		scText	address		isymStart stEnd		scNil	-------		isymStart (struct/union/enum)  stTypedef	scNil	-------		iaux stRegReloc	sc???	value		old register number stForward	sc???	new address	isym to original symbol  stConstant	scInfo	value		--- (scalar) stConstant	scInfo	iss		--- (complex, e.g. string)   *  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

