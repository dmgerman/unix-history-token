begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is a modified version of 'a.out.h'.  It is to be used in all    GNU tools modified to support the i80960 (or tools that operate on    object files created by such tools).        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* All i80960 development is done in a CROSS-DEVELOPMENT environment.  I.e.,    object code is generated on, and executed under the direction of a symbolic    debugger running on, a host system.  We do not want to be subject to the    vagaries of which host it is or whether it supports COFF or a.out format,    or anything else.  We DO want to:      	o always generate the same format object files, regardless of host.    	o have an 'a.out' header that we can modify for our own purposes  	  (the 80960 is typically an embedded processor and may require  	  enhanced linker support that the normal a.out.h header can't  	  accommodate).     As for byte-ordering, the following rules apply:    	o Text and data that is actually downloaded to the target is always  	  in i80960 (little-endian) order.    	o All other numbers (in the header, symbols, relocation directives)  	  are in host byte-order:  object files CANNOT be lifted from a  	  little-end host and used on a big-endian (or vice versa) without  	  modification.   ==> THIS IS NO LONGER TRUE USING BFD.  WE CAN GENERATE ANY BYTE ORDER       FOR THE HEADER, AND READ ANY BYTE ORDER.  PREFERENCE WOULD BE TO       USE LITTLE-ENDIAN BYTE ORDER THROUGHOUT, REGARDLESS OF HOST.<==    	o The downloader ('comm960') takes care to generate a pseudo-header  	  with correct (i80960) byte-ordering before shipping text and data  	  off to the NINDY monitor in the target systems.  Symbols and  	  relocation info are never sent to the target.  */
end_comment

begin_define
define|#
directive|define
name|BMAGIC
value|0415
end_define

begin_comment
comment|/* We don't accept the following (see N_BADMAG macro).    They're just here so GNU code will compile.  */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_comment
comment|/* FILE HEADER   	All 'lengths' are given as a number of bytes.   	All 'alignments' are for relinkable files only;  an alignment of   		'n' indicates the corresponding segment must begin at an   		address that is a multiple of (2**n).  */
end_comment

begin_struct
struct|struct
name|external_exec
block|{
comment|/* Standard stuff */
name|unsigned
name|char
name|e_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* Identifies this as a b.out file */
name|unsigned
name|char
name|e_text
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of text */
name|unsigned
name|char
name|e_data
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of data */
name|unsigned
name|char
name|e_bss
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of uninitialized data area */
name|unsigned
name|char
name|e_syms
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of symbol table */
name|unsigned
name|char
name|e_entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* Runtime start address */
name|unsigned
name|char
name|e_trsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of text relocation info */
name|unsigned
name|char
name|e_drsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Length of data relocation info */
comment|/* Added for i960 */
name|unsigned
name|char
name|e_tload
index|[
literal|4
index|]
decl_stmt|;
comment|/* Text runtime load address */
name|unsigned
name|char
name|e_dload
index|[
literal|4
index|]
decl_stmt|;
comment|/* Data runtime load address */
name|unsigned
name|char
name|e_talign
index|[
literal|1
index|]
decl_stmt|;
comment|/* Alignment of text segment */
name|unsigned
name|char
name|e_dalign
index|[
literal|1
index|]
decl_stmt|;
comment|/* Alignment of data segment */
name|unsigned
name|char
name|e_balign
index|[
literal|1
index|]
decl_stmt|;
comment|/* Alignment of bss segment */
name|unsigned
name|char
name|e_relaxable
index|[
literal|1
index|]
decl_stmt|;
comment|/* Assembled with enough info to allow linker to relax */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(sizeof (struct external_exec))
end_define

begin_comment
comment|/* These macros use the a_xxx field names, since they operate on the exec    structure after it's been byte-swapped and realigned on the host machine.  */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).a_info)!=BMAGIC)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|EXEC_BYTES_SIZE
end_define

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TXTOFF(x) + (x).a_text )
end_define

begin_define
define|#
directive|define
name|N_TROFF
parameter_list|(
name|x
parameter_list|)
value|( N_DATOFF(x) + (x).a_data )
end_define

begin_define
define|#
directive|define
name|N_TRELOFF
value|N_TROFF
end_define

begin_define
define|#
directive|define
name|N_DROFF
parameter_list|(
name|x
parameter_list|)
value|( N_TROFF(x) + (x).a_trsize )
end_define

begin_define
define|#
directive|define
name|N_DRELOFF
value|N_DROFF
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DROFF(x) + (x).a_drsize )
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|( N_SYMOFF(x) + (x).a_syms )
end_define

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
value|( (x).a_dload )
end_define

begin_comment
comment|/* Address of text segment in memory after it is loaded.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|N_TXTADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A single entry in the symbol table.  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|nlist
modifier|*
name|n_next
decl_stmt|;
name|long
name|n_strx
decl_stmt|;
comment|/* Index into string table	*/
block|}
name|n_un
union|;
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* See below				*/
name|char
name|n_other
decl_stmt|;
comment|/* Used in i80960 support -- see below	*/
name|short
name|n_desc
decl_stmt|;
name|unsigned
name|long
name|n_value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Legal values of n_type.  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_comment
comment|/* Undefined symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|2
end_define

begin_comment
comment|/* Absolute symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|4
end_define

begin_comment
comment|/* Text symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|6
end_define

begin_comment
comment|/* Data symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|8
end_define

begin_comment
comment|/* BSS symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_FN
value|31
end_define

begin_comment
comment|/* Filename symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|1
end_define

begin_comment
comment|/* External symbol (OR'd in with one of above)	*/
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|036
end_define

begin_comment
comment|/* Mask for all the type bits			*/
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0340
end_define

begin_comment
comment|/* Mask for all bits used for SDB entries 	*/
end_comment

begin_comment
comment|/* MEANING OF 'n_other'     If non-zero, the 'n_other' fields indicates either a leaf procedure or   a system procedure, as follows:    	1<= n_other<= 32 :  		The symbol is the entry point to a system procedure.  		'n_value' is the address of the entry, as for any other  		procedure.  The system procedure number (which can be used in  		a 'calls' instruction) is (n_other-1).  These entries come from  		'.sysproc' directives.    	n_other == N_CALLNAME  		the symbol is the 'call' entry point to a leaf procedure.  		The *next* symbol in the symbol table must be the corresponding  		'bal' entry point to the procedure (see following).  These  		entries come from '.leafproc' directives in which two different  		symbols are specified (the first one is represented here).  	    	n_other == N_BALNAME  		the symbol is the 'bal' entry point to a leaf procedure.  		These entries result from '.leafproc' directives in which only  		one symbol is specified, or in which the same symbol is  		specified twice.     Note that an N_CALLNAME entry *must* have a corresponding N_BALNAME entry,   but not every N_BALNAME entry must have an N_CALLNAME entry.  */
end_comment

begin_define
define|#
directive|define
name|N_CALLNAME
value|((char)-1)
end_define

begin_define
define|#
directive|define
name|N_BALNAME
value|((char)-2)
end_define

begin_define
define|#
directive|define
name|IS_CALLNAME
parameter_list|(
name|x
parameter_list|)
value|(N_CALLNAME == (x))
end_define

begin_define
define|#
directive|define
name|IS_BALNAME
parameter_list|(
name|x
parameter_list|)
value|(N_BALNAME == (x))
end_define

begin_define
define|#
directive|define
name|IS_OTHER
parameter_list|(
name|x
parameter_list|)
value|((x)>0&& (x)<=32)
end_define

begin_define
define|#
directive|define
name|b_out_relocation_info
value|relocation_info
end_define

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* File address of item to be relocated.  */
name|unsigned
define|#
directive|define
name|r_index
value|r_symbolnum
name|r_symbolnum
range|:
literal|24
decl_stmt|,
comment|/* Index of symbol on which relocation is based, 			   if r_extern is set.  Otherwise set to 			   either N_TEXT, N_DATA, or N_BSS to 			   indicate section on which relocation is 			   based.  */
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 => relocate PC-relative; else absolute 			   On i960, pc-relative implies 24-bit 			   address, absolute implies 32-bit.  */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* Number of bytes to relocate: 			   0 => 1 byte 			   1 => 2 bytes -- used for 13 bit pcrel 			   2 => 4 bytes.  */
name|r_extern
range|:
literal|1
decl_stmt|,
name|r_bsr
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler.  */
name|r_disp
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler.  */
name|r_callj
range|:
literal|1
decl_stmt|,
comment|/* 1 if relocation target is an i960 'callj'.  */
name|r_relaxable
range|:
literal|1
decl_stmt|;
comment|/* 1 if enough info is left to relax the data.  */
block|}
struct|;
end_struct

end_unit

