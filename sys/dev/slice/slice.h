begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1997,1998 Julian Elischer.  All rights reserved.  * julian@freebsd.org  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright notice,  *     this list of conditions and the following disclaimer in the documentation  *     and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE HOLDER OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   *	$Id: $  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|slice_handler
modifier|*
name|sh_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|slice
modifier|*
name|sl_p
typedef|;
end_typedef

begin_struct
struct|struct
name|slicelimits
block|{
name|u_int32_t
name|blksize
decl_stmt|;
comment|/* IN BYTES */
name|u_int64_t
name|slicesize
decl_stmt|;
comment|/* IN BYTES */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|slicelimits
modifier|*
name|slmt_p
typedef|;
end_typedef

begin_comment
comment|/*  * This struct is only used by the IDE geometry guessing hack in   * the MBR and disklabel code, when talked to by the IDE driver with a VERY  * OLD DISK  */
end_comment

begin_struct
struct|struct
name|ide_geom
block|{
name|u_int32_t
name|secpertrack
decl_stmt|;
comment|/* set to 0 if geom not known */
name|u_int16_t
name|trackpercyl
decl_stmt|;
name|u_int32_t
name|cyls
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The probehints are set by the lower handler, to give direction as to   * what handler is probably required above. If a slice is repartitioned,  * these may change e.g. mbr may set 165 meaning "FreeBSD slice" or 4 "DOS".  * -type: a string for the type that should be used.  *        if it's a null string ("") then don't even try find a sub handler.  * 		defined as NO_SUBPART  * 	  if it's a NULL pointer (NULL) then probe all known types.  * -typespecific: A pointer to SOMETHING that teh lower handler thinks  *    may be of interest to the higher hamdlers. The "something" is dependent  *    on the type of the lower handler so the upper handler must know of  *    this in advance. The type of this should be specified in an  *    include file associated with the lower type. This is probably rarely  *    needed.  */
end_comment

begin_struct
struct|struct
name|probehints
block|{
name|char
modifier|*
name|type
decl_stmt|;
comment|/* don't probe, just use this type */
name|void
modifier|*
name|typespecific
decl_stmt|;
comment|/* the lower layer specifies this */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NO_SUBPART
value|""
end_define

begin_comment
comment|/*  * The common slice structure with data, methods and linkages.  */
end_comment

begin_struct
struct|struct
name|slice
block|{
comment|/* Per slice data */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* e.g. sd0 wd0s1, wd0s1a ?? */
name|struct
name|probehints
name|probeinfo
decl_stmt|;
comment|/* how we should probe this */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* this device open, etc. */
name|u_int16_t
name|refs
decl_stmt|;
comment|/* active references, free if 1->0 */
name|u_int16_t
name|opencount
decl_stmt|;
comment|/* actual count of opens if allowed */
name|struct
name|slicelimits
name|limits
decl_stmt|;
comment|/* limits on this slice */
name|sh_p
name|handler_up
decl_stmt|;
comment|/* type methods etc. */
name|void
modifier|*
name|private_up
decl_stmt|;
comment|/* data for the slice type */
name|sh_p
name|handler_down
decl_stmt|;
comment|/* type methods etc. */
name|void
modifier|*
name|private_down
decl_stmt|;
comment|/* data for the slice type */
comment|/*------- fields for the slice device driver -------*/
name|LIST_ENTRY
argument_list|(
argument|slice
argument_list|)
name|hash_list
expr_stmt|;
comment|/* next slice in this bucket */
name|u_int32_t
name|minor
decl_stmt|;
comment|/* the key for finding us */
name|void
modifier|*
name|devfs_btoken
decl_stmt|;
name|void
modifier|*
name|devfs_ctoken
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bit definitions for the slice flags */
end_comment

begin_define
define|#
directive|define
name|SLF_CLOSED
value|0x00000000
end_define

begin_comment
comment|/* slice not open */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_BLK_RD
value|0x00000001
end_define

begin_comment
comment|/* blk slice readable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_BLK_WR
value|0x00000002
end_define

begin_comment
comment|/* blk slice writeable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_BLK
value|(SLF_OPEN_BLK_RD|SLF_OPEN_BLK_WR)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_CHR_RD
value|0x00000004
end_define

begin_comment
comment|/* raw slice readable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_CHR_WR
value|0x00000008
end_define

begin_comment
comment|/* raw slice writeable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_CHR
value|(SLF_OPEN_CHR_RD|SLF_OPEN_CHR_WR)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_DEV_RD
value|(SLF_OPEN_CHR_RD|SLF_OPEN_BLK_RD)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_DEV_WR
value|(SLF_OPEN_CHR_WR|SLF_OPEN_BLK_WR)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_DEV
value|(SLF_OPEN_DEV_RD|SLF_OPEN_DEV_WR)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_UP_RD
value|0x00000010
end_define

begin_comment
comment|/* upper layer is readable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_UP_WR
value|0x00000020
end_define

begin_comment
comment|/* upper layer is writable */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_UP
value|0x00000030
end_define

begin_comment
comment|/* upper layer is open */
end_comment

begin_define
define|#
directive|define
name|SLF_OPEN_WR
value|(SLF_OPEN_UP_WR|SLF_OPEN_DEV_WR)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_RD
value|(SLF_OPEN_UP_RD|SLF_OPEN_DEV_RD)
end_define

begin_define
define|#
directive|define
name|SLF_OPEN_STATE
value|(SLF_OPEN_WR|SLF_OPEN_RD)
end_define

begin_comment
comment|/* Mask open state */
end_comment

begin_define
define|#
directive|define
name|SLF_INVALID
value|0x00000100
end_define

begin_comment
comment|/* Everything aborts */
end_comment

begin_define
define|#
directive|define
name|SLF_LOCKED
value|0x00000200
end_define

begin_comment
comment|/* Hold off, It's busy */
end_comment

begin_define
define|#
directive|define
name|SLF_WANTED
value|0x00000400
end_define

begin_comment
comment|/* I held off, wake me up */
end_comment

begin_comment
comment|/*  * prototypes for slice methods  */
end_comment

begin_typedef
typedef|typedef
name|void
name|sl_h_IO_req_t
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|struct
name|buf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_ioctl_t
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_constructor_t
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_open_t
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|sl_h_close_t
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_revoke_t
parameter_list|(
name|void
modifier|*
name|private
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_claim_t
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|struct
name|slice
modifier|*
name|lower
parameter_list|,
name|void
modifier|*
name|ID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* eg ID=165 for BSD */
end_comment

begin_typedef
typedef|typedef
name|int
name|sl_h_verify_t
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sl_h_upconfig_t
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|slice_handler
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|version
decl_stmt|;
comment|/* the version of this handler */
name|struct
name|slice_handler
modifier|*
name|next
decl_stmt|;
comment|/* next registered type */
name|int
name|refs
decl_stmt|;
comment|/* references to this type */
name|sl_h_constructor_t
modifier|*
name|constructor
decl_stmt|;
comment|/* make new instantiation */
name|sl_h_IO_req_t
modifier|*
name|IOreq
decl_stmt|;
comment|/* IO req downward (to device) */
name|sl_h_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
comment|/* ioctl downward (to device) */
name|sl_h_open_t
modifier|*
name|open
decl_stmt|;
comment|/* downwards travelling open */
name|sl_h_close_t
modifier|*
name|close
decl_stmt|;
comment|/* downwards travelling close */
name|sl_h_revoke_t
modifier|*
name|revoke
decl_stmt|;
comment|/* revoke upwards (towards user ) */
name|sl_h_claim_t
modifier|*
name|claim
decl_stmt|;
comment|/* claim a new slice */
name|sl_h_verify_t
modifier|*
name|verify
decl_stmt|;
comment|/* verify that a slice as it was before */
name|sl_h_upconfig_t
modifier|*
name|upconf
decl_stmt|;
comment|/* config requests from slice below */
block|}
struct|;
end_struct

begin_comment
comment|/*  * general routines that handlers need.  */
end_comment

begin_function_decl
name|int
name|sl_make_slice
parameter_list|(
name|sh_p
name|handler_down
parameter_list|,
name|void
modifier|*
name|private_down
parameter_list|,
name|struct
name|slicelimits
modifier|*
name|limits
parameter_list|,
name|sl_p
modifier|*
name|slicepp
parameter_list|,
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sl_rmslice
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_newtype
parameter_list|(
name|sh_p
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sh_p
name|sl_findtype
parameter_list|(
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sh_p
name|slice_probeall
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockslice
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlockslice
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|slice_readblock
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|int
name|blkno
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|slice_writeblock
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|int
name|blkno
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Definitions for "SLICE" utilities. (handler or device acting on a slice).  */
end_comment

begin_enum
enum|enum
name|slc_who
block|{
name|SLW_ABOVE
block|,
name|SLW_DEVICE
block|}
enum|;
end_enum

begin_comment
comment|/* helps to know who's calling */
end_comment

begin_function_decl
name|void
name|sliceio
parameter_list|(
name|sl_p
name|slice
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|enum
name|slc_who
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sliceopen
parameter_list|(
name|sl_p
name|slice
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|enum
name|slc_who
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sliceclose
parameter_list|(
name|sl_p
name|slice
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|enum
name|slc_who
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sl_unref
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slice_add_device
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slice_remove_device
parameter_list|(
name|sl_p
name|slice
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The geometry guessing HACK functions  */
end_comment

begin_function_decl
name|int
name|mbr_geom_hack
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|struct
name|ide_geom
modifier|*
name|geom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dkl_geom_hack
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|struct
name|ide_geom
modifier|*
name|geom
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The routine to produce a dummy disklabel from a slice.  * Lives in disklabel.c because that's where everyhting is in scope,  * but is used in slice_device.c.  XXX hack.  */
end_comment

begin_function_decl
name|int
name|dkl_dummy_ioctl
parameter_list|(
name|struct
name|slice
modifier|*
name|slice
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * debugging   */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|RR
value|printf(__FUNCTION__ " called\n")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RR
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

