begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: procfs.h,v 1.1 1993/12/12 12:27:03 davidg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCFS_H_
end_define

begin_struct
struct|struct
name|procmap
block|{
comment|/* Simplified VM maps */
name|vm_offset_t
name|vaddr
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
name|vm_offset_t
name|offset
decl_stmt|;
name|vm_prot_t
name|prot
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmfd
block|{
comment|/* Mapped file descriptor */
name|vm_offset_t
name|vaddr
decl_stmt|;
comment|/* IN */
name|int
name|fd
decl_stmt|;
comment|/* OUT */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|vmet
block|{
name|PFS_END
block|,
name|PFS_PRMAP
block|,
name|PFS_OBJINFO
block|}
enum|;
end_enum

begin_struct
struct|struct
name|objinfo
block|{
name|int
name|ref_count
decl_stmt|;
comment|/* ref_count for object */
name|int
name|rss_map
decl_stmt|;
comment|/* rss within the map entry */
name|int
name|persist
decl_stmt|;
comment|/* persist flag */
name|int
name|internal
decl_stmt|;
comment|/* internal flag */
name|vm_offset_t
name|offset
decl_stmt|;
comment|/* offset into object */
name|vm_offset_t
name|size
decl_stmt|;
comment|/* total size of object */
name|struct
name|vm_page
name|pages
index|[
literal|0
index|]
decl_stmt|;
comment|/* pages */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|procvminfo
block|{
comment|/* Full proc VM info */
name|enum
name|vmet
name|entrytype
decl_stmt|;
comment|/* type of entry */
union|union
block|{
name|struct
name|procmap
name|pm
decl_stmt|;
comment|/* proc map entry */
name|struct
name|objinfo
name|oi
decl_stmt|;
comment|/* object info entry */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|unsigned
name|long
name|fltset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIOCGPINFO
value|_IOR('P', 0, struct kinfo_proc)
end_define

begin_define
define|#
directive|define
name|PIOCGSIGSET
value|_IOR('P', 1, sigset_t)
end_define

begin_define
define|#
directive|define
name|PIOCSSIGSET
value|_IOW('P', 2, sigset_t)
end_define

begin_define
define|#
directive|define
name|PIOCGFLTSET
value|_IOR('P', 3, fltset_t)
end_define

begin_define
define|#
directive|define
name|PIOCSFLTSET
value|_IOW('P', 4, fltset_t)
end_define

begin_define
define|#
directive|define
name|PIOCGNMAP
value|_IOR('P', 5, int)
end_define

begin_define
define|#
directive|define
name|PIOCGMAP
value|_IO ('P', 6)
end_define

begin_define
define|#
directive|define
name|PIOCGMAPFD
value|_IOWR('P', 7, struct vmfd)
end_define

begin_define
define|#
directive|define
name|PIOCGNVMINFO
value|_IOR('P', 8, int)
end_define

begin_define
define|#
directive|define
name|PIOCGVMINFO
value|_IO ('P', 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PROCFS_H_ */
end_comment

end_unit

