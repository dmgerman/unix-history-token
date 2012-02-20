begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cd9660.h,v 1.17 2011/06/23 02:35:56 enami Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Daniel Watt, Walter Deignan, Ryan Gabrys, Alan  * Perez-Rathke and Ram Vedam.  All rights reserved.  *  * This code was written by Daniel Watt, Walter Deignan, Ryan Gabrys,  * Alan Perez-Rathke and Ram Vedam.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DANIEL WATT, WALTER DEIGNAN, RYAN  * GABRYS, ALAN PEREZ-RATHKE AND RAM VEDAM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL DANIEL WATT, WALTER DEIGNAN, RYAN  * GABRYS, ALAN PEREZ-RATHKE AND RAM VEDAM BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE,DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAKEFS_CD9660_H
end_ifndef

begin_define
define|#
directive|define
name|_MAKEFS_CD9660_H
end_define

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|"makefs.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_include
include|#
directive|include
file|"iso_rrip.h"
end_include

begin_include
include|#
directive|include
file|"cd9660/cd9660_eltorito.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|INODE_WARNX
parameter_list|(
name|__x
parameter_list|)
value|warnx __x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|INODE_WARNX
parameter_list|(
name|__x
parameter_list|)
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
name|CD9660MAXPATH
value|4096
end_define

begin_define
define|#
directive|define
name|ISO_STRING_FILTER_NONE
value|= 0x00
end_define

begin_define
define|#
directive|define
name|ISO_STRING_FILTER_DCHARS
value|= 0x01
end_define

begin_define
define|#
directive|define
name|ISO_STRING_FILTER_ACHARS
value|= 0x02
end_define

begin_comment
comment|/* Extended preferences type, in the spirit of what makefs gives us (only ints) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|shortName
decl_stmt|;
comment|/* Short option */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* option name */
name|char
modifier|*
name|value
decl_stmt|;
comment|/* where to stuff the value */
name|int
name|minLength
decl_stmt|;
comment|/* minimum for value */
name|int
name|maxLength
decl_stmt|;
comment|/* maximum for value */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* option description */
name|int
name|filterFlags
decl_stmt|;
block|}
name|string_option_t
typedef|;
end_typedef

begin_comment
comment|/******** STRUCTURES **********/
end_comment

begin_comment
comment|/*Defaults*/
end_comment

begin_define
define|#
directive|define
name|ISO_DEFAULT_VOLUMEID
value|"MAKEFS_CD9660_IMAGE"
end_define

begin_define
define|#
directive|define
name|ISO_DEFAULT_APPID
value|"MAKEFS"
end_define

begin_define
define|#
directive|define
name|ISO_DEFAULT_PUBLISHER
value|"MAKEFS"
end_define

begin_define
define|#
directive|define
name|ISO_DEFAULT_PREPARER
value|"MAKEFS"
end_define

begin_define
define|#
directive|define
name|ISO_VOLUME_DESCRIPTOR_STANDARD_ID
value|"CD001"
end_define

begin_define
define|#
directive|define
name|ISO_VOLUME_DESCRIPTOR_BOOT
value|0
end_define

begin_define
define|#
directive|define
name|ISO_VOLUME_DESCRIPTOR_PVD
value|1
end_define

begin_define
define|#
directive|define
name|ISO_VOLUME_DESCRIPTOR_TERMINATOR
value|255
end_define

begin_comment
comment|/*30 for name and extension, as well as version number and padding bit*/
end_comment

begin_define
define|#
directive|define
name|ISO_FILENAME_MAXLENGTH_BEFORE_VERSION
value|30
end_define

begin_define
define|#
directive|define
name|ISO_FILENAME_MAXLENGTH
value|36
end_define

begin_define
define|#
directive|define
name|ISO_FILENAME_MAXLENGTH_WITH_PADDING
value|37
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_CLEAR
value|0x00
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_HIDDEN
value|0x01
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_DIRECTORY
value|0x02
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_ASSOCIATED
value|0x04
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_PERMISSIONS
value|0x08
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_RESERVED5
value|0x10
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_RESERVED6
value|0x20
end_define

begin_define
define|#
directive|define
name|ISO_FLAG_FINAL_RECORD
value|0x40
end_define

begin_define
define|#
directive|define
name|ISO_PATHTABLE_ENTRY_BASESIZE
value|8
end_define

begin_define
define|#
directive|define
name|ISO_RRIP_DEFAULT_MOVE_DIR_NAME
value|"RR_MOVED"
end_define

begin_define
define|#
directive|define
name|RRIP_DEFAULT_MOVE_DIR_NAME
value|".rr_moved"
end_define

begin_define
define|#
directive|define
name|CD9660_BLOCKS
parameter_list|(
name|__sector_size
parameter_list|,
name|__bytes
parameter_list|)
define|\
value|howmany((__bytes), (__sector_size))
end_define

begin_define
define|#
directive|define
name|CD9660_MEM_ALLOC_ERROR
parameter_list|(
name|_F
parameter_list|)
define|\
value|err(EXIT_FAILURE, "%s, %s l. %d", _F, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|CD9660_IS_COMMAND_ARG_DUAL
parameter_list|(
name|var
parameter_list|,
name|short
parameter_list|,
name|long
parameter_list|)
define|\
value|(strcmp((var),(short)) == 0) || (strcmp((var),(long))==0)
end_define

begin_define
define|#
directive|define
name|CD9660_IS_COMMAND_ARG
parameter_list|(
name|var
parameter_list|,
name|arg
parameter_list|)
define|\
value|(strcmp((var),(arg)) == 0)
end_define

begin_define
define|#
directive|define
name|CD9660_TYPE_FILE
value|0x01
end_define

begin_define
define|#
directive|define
name|CD9660_TYPE_DIR
value|0x02
end_define

begin_define
define|#
directive|define
name|CD9660_TYPE_DOT
value|0x04
end_define

begin_define
define|#
directive|define
name|CD9660_TYPE_DOTDOT
value|0x08
end_define

begin_define
define|#
directive|define
name|CD9660_TYPE_VIRTUAL
value|0x80
end_define

begin_define
define|#
directive|define
name|CD9660_INODE_HASH_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CD9660_SECTOR_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|CD9660_END_PADDING
value|150
end_define

begin_comment
comment|/* Slight modification of the ISO structure in iso.h */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_iso_directory_record_cd9660
block|{
name|u_char
name|length
index|[
name|ISODCL
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* 711 */
name|u_char
name|ext_attr_length
index|[
name|ISODCL
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
index|]
decl_stmt|;
comment|/* 711 */
name|u_char
name|extent
index|[
name|ISODCL
argument_list|(
literal|3
argument_list|,
literal|10
argument_list|)
index|]
decl_stmt|;
comment|/* 733 */
name|u_char
name|size
index|[
name|ISODCL
argument_list|(
literal|11
argument_list|,
literal|18
argument_list|)
index|]
decl_stmt|;
comment|/* 733 */
name|u_char
name|date
index|[
name|ISODCL
argument_list|(
literal|19
argument_list|,
literal|25
argument_list|)
index|]
decl_stmt|;
comment|/* 7 by 711 */
name|u_char
name|flags
index|[
name|ISODCL
argument_list|(
literal|26
argument_list|,
literal|26
argument_list|)
index|]
decl_stmt|;
name|u_char
name|file_unit_size
index|[
name|ISODCL
argument_list|(
literal|27
argument_list|,
literal|27
argument_list|)
index|]
decl_stmt|;
comment|/* 711 */
name|u_char
name|interleave
index|[
name|ISODCL
argument_list|(
literal|28
argument_list|,
literal|28
argument_list|)
index|]
decl_stmt|;
comment|/* 711 */
name|u_char
name|volume_sequence_number
index|[
name|ISODCL
argument_list|(
literal|29
argument_list|,
literal|32
argument_list|)
index|]
decl_stmt|;
comment|/* 723 */
name|u_char
name|name_len
index|[
name|ISODCL
argument_list|(
literal|33
argument_list|,
literal|33
argument_list|)
index|]
decl_stmt|;
comment|/* 711 */
name|char
name|name
index|[
name|ISO_FILENAME_MAXLENGTH_WITH_PADDING
index|]
decl_stmt|;
block|}
name|iso_directory_record_cd9660
typedef|;
end_typedef

begin_comment
comment|/* TODO: Lots of optimization of this structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cd9660node
block|{
name|u_char
name|type
decl_stmt|;
comment|/* Used internally */
comment|/* Tree structure */
name|struct
name|_cd9660node
modifier|*
name|parent
decl_stmt|;
comment|/* parent (NULL if root) */
name|TAILQ_HEAD
argument_list|(
argument|cd9660_children_head
argument_list|,
argument|_cd9660node
argument_list|)
name|cn_children
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|_cd9660node
argument_list|)
name|cn_next_child
expr_stmt|;
name|struct
name|_cd9660node
modifier|*
name|dot_record
decl_stmt|;
comment|/* For directories, used mainly in RRIP */
name|struct
name|_cd9660node
modifier|*
name|dot_dot_record
decl_stmt|;
name|fsnode
modifier|*
name|node
decl_stmt|;
comment|/* pointer to fsnode */
name|struct
name|_iso_directory_record_cd9660
modifier|*
name|isoDirRecord
decl_stmt|;
name|struct
name|iso_extended_attributes
modifier|*
name|isoExtAttributes
decl_stmt|;
comment|/***** SIZE CALCULATION *****/
comment|/*already stored in isoDirRecord, but this is an int version, and will be 		copied to isoDirRecord on writing*/
name|uint32_t
name|fileDataSector
decl_stmt|;
comment|/* 	 * same thing, though some notes: 	 * If a file, this is the file size 	 * If a directory, this is the size of all its children's 	 *	directory records 	 * plus necessary padding 	 */
name|int64_t
name|fileDataLength
decl_stmt|;
name|int64_t
name|fileSectorsUsed
decl_stmt|;
name|int
name|fileRecordSize
decl_stmt|;
comment|/*copy of a variable, int for quicker calculations*/
comment|/* Old name, used for renaming - needs to be optimized but low priority */
name|char
name|o_name
index|[
name|ISO_FILENAME_MAXLENGTH_WITH_PADDING
index|]
decl_stmt|;
comment|/***** SPACE RESERVED FOR EXTENSIONS *****/
comment|/* For memory efficiency's sake - we should move this to a separate struct 		and point to null if not needed */
comment|/* For Rock Ridge */
name|struct
name|_cd9660node
modifier|*
name|rr_real_parent
decl_stmt|,
modifier|*
name|rr_relocated
decl_stmt|;
name|int64_t
name|susp_entry_size
decl_stmt|;
name|int64_t
name|susp_dot_entry_size
decl_stmt|;
name|int64_t
name|susp_dot_dot_entry_size
decl_stmt|;
comment|/* Continuation area stuff */
name|int64_t
name|susp_entry_ce_start
decl_stmt|;
name|int64_t
name|susp_dot_ce_start
decl_stmt|;
name|int64_t
name|susp_dot_dot_ce_start
decl_stmt|;
name|int64_t
name|susp_entry_ce_length
decl_stmt|;
name|int64_t
name|susp_dot_ce_length
decl_stmt|;
name|int64_t
name|susp_dot_dot_ce_length
decl_stmt|;
comment|/* Data to put at the end of the System Use field */
name|int64_t
name|su_tail_size
decl_stmt|;
name|char
modifier|*
name|su_tail_data
decl_stmt|;
comment|/*** PATH TABLE STUFF ***/
name|int
name|level
decl_stmt|;
comment|/*depth*/
name|int
name|ptnumber
decl_stmt|;
name|struct
name|_cd9660node
modifier|*
name|ptnext
decl_stmt|,
modifier|*
name|ptprev
decl_stmt|,
modifier|*
name|ptlast
decl_stmt|;
comment|/* SUSP entries */
name|TAILQ_HEAD
argument_list|(
argument|susp_linked_list
argument_list|,
argument|ISO_SUSP_ATTRIBUTES
argument_list|)
name|head
expr_stmt|;
block|}
name|cd9660node
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_path_table_entry
block|{
name|u_char
name|length
index|[
name|ISODCL
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
index|]
decl_stmt|;
name|u_char
name|extended_attribute_length
index|[
name|ISODCL
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
index|]
decl_stmt|;
name|u_char
name|first_sector
index|[
name|ISODCL
argument_list|(
literal|3
argument_list|,
literal|6
argument_list|)
index|]
decl_stmt|;
name|u_char
name|parent_number
index|[
name|ISODCL
argument_list|(
literal|7
argument_list|,
literal|8
argument_list|)
index|]
decl_stmt|;
name|u_char
name|name
index|[
name|ISO_FILENAME_MAXLENGTH_WITH_PADDING
index|]
decl_stmt|;
block|}
name|path_table_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_volume_descriptor
block|{
name|u_char
modifier|*
name|volumeDescriptorData
decl_stmt|;
comment|/*ALWAYS 2048 bytes long*/
name|int64_t
name|sector
decl_stmt|;
name|struct
name|_volume_descriptor
modifier|*
name|next
decl_stmt|;
block|}
name|volume_descriptor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_iso9660_disk
block|{
name|int
name|sectorSize
decl_stmt|;
name|struct
name|iso_primary_descriptor
name|primaryDescriptor
decl_stmt|;
name|struct
name|iso_supplementary_descriptor
name|supplementaryDescriptor
decl_stmt|;
name|volume_descriptor
modifier|*
name|firstVolumeDescriptor
decl_stmt|;
name|cd9660node
modifier|*
name|rootNode
decl_stmt|;
comment|/* Important sector numbers here */
comment|/* primaryDescriptor.type_l_path_table*/
name|int64_t
name|primaryBigEndianTableSector
decl_stmt|;
comment|/* primaryDescriptor.type_m_path_table*/
name|int64_t
name|primaryLittleEndianTableSector
decl_stmt|;
comment|/* primaryDescriptor.opt_type_l_path_table*/
name|int64_t
name|secondaryBigEndianTableSector
decl_stmt|;
comment|/* primaryDescriptor.opt_type_m_path_table*/
name|int64_t
name|secondaryLittleEndianTableSector
decl_stmt|;
comment|/* primaryDescriptor.path_table_size*/
name|int
name|pathTableLength
decl_stmt|;
name|int64_t
name|dataFirstSector
decl_stmt|;
name|int64_t
name|totalSectors
decl_stmt|;
comment|/* OPTIONS GO HERE */
name|int
name|isoLevel
decl_stmt|;
name|int
name|include_padding_areas
decl_stmt|;
name|int
name|follow_sym_links
decl_stmt|;
name|int
name|verbose_level
decl_stmt|;
name|int
name|displayHelp
decl_stmt|;
name|int
name|keep_bad_images
decl_stmt|;
comment|/* SUSP options and variables */
name|int64_t
name|susp_continuation_area_start_sector
decl_stmt|;
name|int64_t
name|susp_continuation_area_size
decl_stmt|;
name|int64_t
name|susp_continuation_area_current_free
decl_stmt|;
name|int
name|rock_ridge_enabled
decl_stmt|;
comment|/* Other Rock Ridge Variables */
name|char
modifier|*
name|rock_ridge_renamed_dir_name
decl_stmt|;
name|int
name|rock_ridge_move_count
decl_stmt|;
name|cd9660node
modifier|*
name|rr_moved_dir
decl_stmt|;
name|int
name|archimedes_enabled
decl_stmt|;
name|int
name|chrp_boot
decl_stmt|;
comment|/* Spec breaking options */
name|u_char
name|allow_deep_trees
decl_stmt|;
name|u_char
name|allow_start_dot
decl_stmt|;
name|u_char
name|allow_max_name
decl_stmt|;
comment|/* Allow 37 char filenames*/
name|u_char
name|allow_illegal_chars
decl_stmt|;
comment|/* ~, !, # */
name|u_char
name|allow_lowercase
decl_stmt|;
name|u_char
name|allow_multidot
decl_stmt|;
name|u_char
name|omit_trailing_period
decl_stmt|;
comment|/* BOOT INFORMATION HERE */
name|int
name|has_generic_bootimage
decl_stmt|;
comment|/* Default to 0 */
name|char
modifier|*
name|generic_bootimage
decl_stmt|;
name|int
name|is_bootable
decl_stmt|;
comment|/* Default to 0 */
name|int64_t
name|boot_catalog_sector
decl_stmt|;
name|boot_volume_descriptor
modifier|*
name|boot_descriptor
decl_stmt|;
name|char
modifier|*
name|boot_image_directory
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|boot_image_list
argument_list|,
argument|cd9660_boot_image
argument_list|)
name|boot_images
expr_stmt|;
name|int
name|image_serialno
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument|boot_catalog_entries
argument_list|,
argument|boot_catalog_entry
argument_list|)
name|boot_entries
expr_stmt|;
block|}
name|iso9660_disk
typedef|;
end_typedef

begin_comment
comment|/******** GLOBAL VARIABLES ***********/
end_comment

begin_decl_stmt
specifier|extern
name|iso9660_disk
name|diskStructure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************ FUNCTIONS **************/
end_comment

begin_function_decl
name|int
name|cd9660_valid_a_chars
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_valid_d_chars
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_uppercase_characters
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ISO Data Types */
end_comment

begin_function_decl
name|void
name|cd9660_721
parameter_list|(
name|uint16_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_731
parameter_list|(
name|uint32_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_722
parameter_list|(
name|uint16_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_732
parameter_list|(
name|uint32_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_bothendian_dword
parameter_list|(
name|uint32_t
name|dw
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_bothendian_word
parameter_list|(
name|uint16_t
name|dw
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_set_date
parameter_list|(
name|char
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_time_8426
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_time_915
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*** Boot Functions ***/
end_comment

begin_function_decl
name|int
name|cd9660_write_generic_bootimage
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_add_generic_bootimage
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_write_boot
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_add_boot_disk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_eltorito_add_boot_option
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_setup_boot
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_setup_boot_volume_descriptor
parameter_list|(
name|volume_descriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*** Write Functions ***/
end_comment

begin_function_decl
name|int
name|cd9660_write_image
parameter_list|(
specifier|const
name|char
modifier|*
name|image
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_copy_file
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|off_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_compute_full_filename
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_compute_record_size
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Debugging functions */
end_comment

begin_function_decl
name|void
name|debug_print_tree
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_print_path_tree
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_print_volume_descriptor_information
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_to_xml_ptentry
parameter_list|(
name|path_table_entry
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_to_xml_path_table
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_to_xml
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|debug_get_encoded_number
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_integer
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_directory_record_9_1
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|debug_dump_to_xml_volume_descriptor
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_pad_string_spaces
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

