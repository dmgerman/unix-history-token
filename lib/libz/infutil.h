begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infutil.h -- types and macros common to blocks and codes  * Copyright (C) 1995-1998 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INFUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_INFUTIL_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|TYPE
block|,
comment|/* get type bits (3, including end bit) */
name|LENS
block|,
comment|/* get lengths for stored */
name|STORED
block|,
comment|/* processing stored block */
name|TABLE
block|,
comment|/* get table lengths */
name|BTREE
block|,
comment|/* get bit lengths tree for a dynamic block */
name|DTREE
block|,
comment|/* get length, distance trees for a dynamic block */
name|CODES
block|,
comment|/* processing fixed or dynamic block */
name|DRY
block|,
comment|/* output remaining window bytes */
name|DONE
block|,
comment|/* finished last block, done */
name|BAD
block|}
comment|/* got a data error--stuck here */
name|inflate_block_mode
typedef|;
end_typedef

begin_comment
comment|/* inflate blocks semi-private state */
end_comment

begin_struct
struct|struct
name|inflate_blocks_state
block|{
comment|/* mode */
name|inflate_block_mode
name|mode
decl_stmt|;
comment|/* current inflate_block mode */
comment|/* mode dependent information */
union|union
block|{
name|uInt
name|left
decl_stmt|;
comment|/* if STORED, bytes left to copy */
struct|struct
block|{
name|uInt
name|table
decl_stmt|;
comment|/* table lengths (14 bits) */
name|uInt
name|index
decl_stmt|;
comment|/* index into blens (or border) */
name|uIntf
modifier|*
name|blens
decl_stmt|;
comment|/* bit lengths of codes */
name|uInt
name|bb
decl_stmt|;
comment|/* bit length tree depth */
name|inflate_huft
modifier|*
name|tb
decl_stmt|;
comment|/* bit length decoding tree */
block|}
name|trees
struct|;
comment|/* if DTREE, decoding info for trees */
struct|struct
block|{
name|inflate_codes_statef
modifier|*
name|codes
decl_stmt|;
block|}
name|decode
struct|;
comment|/* if CODES, current state */
block|}
name|sub
union|;
comment|/* submode */
name|uInt
name|last
decl_stmt|;
comment|/* true if this block is the last block */
comment|/* mode independent information */
name|uInt
name|bitk
decl_stmt|;
comment|/* bits in bit buffer */
name|uLong
name|bitb
decl_stmt|;
comment|/* bit buffer */
name|inflate_huft
modifier|*
name|hufts
decl_stmt|;
comment|/* single malloc for tree space */
name|Bytef
modifier|*
name|window
decl_stmt|;
comment|/* sliding window */
name|Bytef
modifier|*
name|end
decl_stmt|;
comment|/* one byte after sliding window */
name|Bytef
modifier|*
name|read
decl_stmt|;
comment|/* window read pointer */
name|Bytef
modifier|*
name|write
decl_stmt|;
comment|/* window write pointer */
name|check_func
name|checkfn
decl_stmt|;
comment|/* check function */
name|uLong
name|check
decl_stmt|;
comment|/* check on output */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for inflate input/output */
end_comment

begin_comment
comment|/*   update pointers and return */
end_comment

begin_define
define|#
directive|define
name|UPDBITS
value|{s->bitb=b;s->bitk=k;}
end_define

begin_define
define|#
directive|define
name|UPDIN
value|{z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
end_define

begin_define
define|#
directive|define
name|UPDOUT
value|{s->write=q;}
end_define

begin_define
define|#
directive|define
name|UPDATE
value|{UPDBITS UPDIN UPDOUT}
end_define

begin_define
define|#
directive|define
name|LEAVE
value|{UPDATE return inflate_flush(s,z,r);}
end_define

begin_comment
comment|/*   get bytes and bits */
end_comment

begin_define
define|#
directive|define
name|LOADIN
value|{p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
end_define

begin_define
define|#
directive|define
name|NEEDBYTE
value|{if(n)r=Z_OK;else LEAVE}
end_define

begin_define
define|#
directive|define
name|NEXTBYTE
value|(n--,*p++)
end_define

begin_define
define|#
directive|define
name|NEEDBITS
parameter_list|(
name|j
parameter_list|)
value|{while(k<(j)){NEEDBYTE;b|=((uLong)NEXTBYTE)<<k;k+=8;}}
end_define

begin_define
define|#
directive|define
name|DUMPBITS
parameter_list|(
name|j
parameter_list|)
value|{b>>=(j);k-=(j);}
end_define

begin_comment
comment|/*   output bytes */
end_comment

begin_define
define|#
directive|define
name|WAVAIL
value|(uInt)(q<s->read?s->read-q-1:s->end-q)
end_define

begin_define
define|#
directive|define
name|LOADOUT
value|{q=s->write;m=(uInt)WAVAIL;}
end_define

begin_define
define|#
directive|define
name|WRAP
value|{if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}
end_define

begin_define
define|#
directive|define
name|FLUSH
value|{UPDOUT r=inflate_flush(s,z,r); LOADOUT}
end_define

begin_define
define|#
directive|define
name|NEEDOUT
value|{if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
end_define

begin_define
define|#
directive|define
name|OUTBYTE
parameter_list|(
name|a
parameter_list|)
value|{*q++=(Byte)(a);m--;}
end_define

begin_comment
comment|/*   load local pointers */
end_comment

begin_define
define|#
directive|define
name|LOAD
value|{LOADIN LOADOUT}
end_define

begin_comment
comment|/* masks for lower bits (size given to avoid silly warnings with Visual C++) */
end_comment

begin_decl_stmt
specifier|extern
name|uInt
name|inflate_mask
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* copy as much as possible from the sliding window to the output area */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_flush
name|OF
argument_list|(
operator|(
name|inflate_blocks_statef
operator|*
operator|,
name|z_streamp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|internal_state
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for buggy compilers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

