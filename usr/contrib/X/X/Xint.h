begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/* $Header: Xint.h,v 10.8 86/02/01 15:15:27 tony Rel $ */
end_comment

begin_comment
comment|/* Internal definitions for X server */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"Xproto.h"
end_include

begin_include
include|#
directive|include
file|"vsinput.h"
end_include

begin_include
include|#
directive|include
file|"Xdev.h"
end_include

begin_define
define|#
directive|define
name|funclim
value|16
end_define

begin_comment
comment|/* max GXfunction + 1 */
end_comment

begin_define
define|#
directive|define
name|maxsocks
value|(NOFILE - 1)
end_define

begin_comment
comment|/* maximum open sockets */
end_comment

begin_define
define|#
directive|define
name|mskcnt
value|((maxsocks + 31) / 32)
end_define

begin_comment
comment|/* size of bit array */
end_comment

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|copybits
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst[0] = src[0]
end_define

begin_define
define|#
directive|define
name|clearbits
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|==
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|copybits
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst[0] = src[0]; dst[1] = src[1]
end_define

begin_define
define|#
directive|define
name|clearbits
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0; buf[1] = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|==
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|copybits
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
end_define

begin_define
define|#
directive|define
name|clearbits
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0; buf[1] = 0; buf[2] = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|>
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|copybits
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|bcopy((caddr_t) src, (caddr_t) dst, sizeof (src))
end_define

begin_define
define|#
directive|define
name|clearbits
parameter_list|(
name|buf
parameter_list|)
value|bzero((caddr_t) buf, sizeof (buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|bitmask
parameter_list|(
name|i
parameter_list|)
value|(1<< (i))
end_define

begin_define
define|#
directive|define
name|maskidx
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|>
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|bitmask
parameter_list|(
name|i
parameter_list|)
value|(1<< ((i)& 31))
end_define

begin_define
define|#
directive|define
name|maskidx
parameter_list|(
name|i
parameter_list|)
value|((i)>> 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|maskword
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|buf[maskidx(i)]
end_define

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|maskword(buf, i) |= bitmask(i)
end_define

begin_define
define|#
directive|define
name|bitclear
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|maskword(buf, i)&= ~bitmask(i)
end_define

begin_define
define|#
directive|define
name|getbit
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|(maskword(buf, i)& bitmask(i))
end_define

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|singlebit
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|maskword(buf, i) = bitmask(i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|mskcnt
operator|>
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|singlebit
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|clearbits(buf); bitset(buf, i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_resource
block|{
name|struct
name|_resource
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* chain pointers */
name|caddr_t
name|value
decl_stmt|;
comment|/* the object */
name|char
name|type
decl_stmt|;
comment|/* RT_* */
name|long
name|id
decl_stmt|;
comment|/* resource id */
block|}
name|RESOURCE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RT_FREE
value|0
end_define

begin_define
define|#
directive|define
name|RT_WINDOW
value|1
end_define

begin_define
define|#
directive|define
name|RT_FONT
value|2
end_define

begin_define
define|#
directive|define
name|RT_BITMAP
value|3
end_define

begin_define
define|#
directive|define
name|RT_PIXMAP
value|4
end_define

begin_define
define|#
directive|define
name|RT_CURSOR
value|5
end_define

begin_define
define|#
directive|define
name|RESIDX
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xffff)
end_define

begin_comment
comment|/* index in low 16 bits */
end_comment

begin_comment
comment|/* Now define the rectangle types and the rectangle itself */
end_comment

begin_define
define|#
directive|define
name|contents_rec
value|0
end_define

begin_define
define|#
directive|define
name|new_rec
value|1
end_define

begin_define
define|#
directive|define
name|border_rec
value|2
end_define

begin_comment
comment|/* The first 4 components must match RASTER */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rec
block|{
name|short
name|bottom
decl_stmt|;
comment|/* not inclusive */
name|short
name|right
decl_stmt|;
comment|/* not inclusive */
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
name|short
name|type
decl_stmt|;
comment|/* one of *_rec types above */
name|short
name|internal
decl_stmt|;
comment|/* 1: not head of malloc() area */
name|struct
name|rec
modifier|*
name|next
decl_stmt|;
comment|/* chain pointer */
block|}
name|RECTANGLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* components must match REGION */
name|short
name|bottom
decl_stmt|;
comment|/* not inclusive */
name|short
name|right
decl_stmt|;
comment|/* not inclusive */
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
block|}
name|RASTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* component order dictated by protocol */
name|short
name|height
decl_stmt|;
name|short
name|width
decl_stmt|;
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
block|}
name|REGION
typedef|;
end_typedef

begin_comment
comment|/* A window */
end_comment

begin_comment
comment|/*  If mapped is true, coords are absolute (i.e. relative only to the root  *  window).  Otherwise, they are relative to the parent window's origin.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|wnode
block|{
name|RASTER
name|full
decl_stmt|;
comment|/* Inside dimensions not clipped by parent */
name|RASTER
name|vs
decl_stmt|;
comment|/* Inside dimensions clipped by parent */
name|RASTER
name|ovs
decl_stmt|;
comment|/* Outside dimensions clipped by parent */
name|CLIP
name|clip
decl_stmt|;
comment|/* vs as clipping rectangle */
name|struct
name|wnode
modifier|*
name|parent
decl_stmt|;
comment|/* Who contains this window */
name|struct
name|wnode
modifier|*
name|next_sib
decl_stmt|;
comment|/* Other windows it contains */
name|struct
name|wnode
modifier|*
name|prev_sib
decl_stmt|;
comment|/* (linked two ways) */
name|struct
name|wnode
modifier|*
name|first_child
decl_stmt|;
comment|/* Bottom-most window this contains */
name|struct
name|wnode
modifier|*
name|last_child
decl_stmt|;
comment|/* Top-most window it contains */
name|RECTANGLE
modifier|*
name|visible
decl_stmt|;
comment|/* List of visible rectangles */
name|RECTANGLE
modifier|*
name|cmvisible
decl_stmt|;
comment|/* List of visible rectangles when clipmode */
name|ushort
name|level
decl_stmt|;
comment|/* The level in the window hierarchy */
comment|/*	child.level = parent.level + 1 */
name|char
name|unobscured
decl_stmt|;
comment|/* 0: obscured, 1: unobscured (3 temp), OB_* */
name|char
name|kind
decl_stmt|;
comment|/* 0: transparent, 1: opaque, 2: icon */
name|char
name|clipmode
decl_stmt|;
comment|/* 0: clipped, 1: draw-thru */
name|char
name|tilemode
decl_stmt|;
comment|/* 0: absolute, 1: relative */
name|char
name|mapped
decl_stmt|;
comment|/* 0: unmapped, 1: mapped */
name|char
name|should_be_mapped
decl_stmt|;
comment|/* 0: unmapped, 1: should be mapped */
name|CURSOR
modifier|*
name|cursor
decl_stmt|;
comment|/* The cursor information */
name|PIXMAP
modifier|*
name|tile
decl_stmt|;
comment|/* The background tile */
name|PIXMAP
modifier|*
name|border
decl_stmt|;
comment|/* The border tile */
name|short
name|bwidth
decl_stmt|;
comment|/* The border width */
name|char
name|bgrabs
decl_stmt|;
comment|/* Button grab count */
name|char
name|internal
decl_stmt|;
comment|/* 1: not head of malloc() area */
name|long
name|mask
decl_stmt|;
comment|/* The input event mask */
name|int
name|client
decl_stmt|;
comment|/* Client asking for events */
name|long
name|rid
decl_stmt|;
comment|/* Resource identifier */
name|short
name|width0
decl_stmt|;
comment|/* Minimum width */
name|short
name|widthinc
decl_stmt|;
comment|/* Width increment */
name|short
name|height0
decl_stmt|;
comment|/* Minimum height */
name|short
name|heightinc
decl_stmt|;
comment|/* Height increment */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Window name */
name|struct
name|wnode
modifier|*
name|icon
decl_stmt|;
comment|/* Icon or normal window */
name|struct
name|wnode
modifier|*
name|next
decl_stmt|;
comment|/* mapped_list chain pointers */
name|struct
name|wnode
modifier|*
name|prev
decl_stmt|;
block|}
name|WINDOW
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OB_NOT
value|0
end_define

begin_define
define|#
directive|define
name|OB_YES
value|1
end_define

begin_define
define|#
directive|define
name|OB_TMP
value|3
end_define

begin_comment
comment|/* not 2, for lsb test */
end_comment

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)>= (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<= (y) ? (x) : (y))
end_define

begin_comment
comment|/* create a new rectangle */
end_comment

begin_define
define|#
directive|define
name|NEWRECT
parameter_list|(
name|r
parameter_list|,
name|lf
parameter_list|,
name|rt
parameter_list|,
name|tp
parameter_list|,
name|bt
parameter_list|,
name|ty
parameter_list|)
value|if ((r = free_rectangles) == NULL)\ 					    r = Alloc_rectangle ();\ 					free_rectangles = r->next;\ 					r->left = lf; r->right = rt;\ 					r->top = tp; r->bottom = bt;\ 					r->type = ty
end_define

begin_comment
comment|/* create a new rectangle from a raster */
end_comment

begin_define
define|#
directive|define
name|RASTRECT
parameter_list|(
name|r
parameter_list|,
name|rs
parameter_list|,
name|ty
parameter_list|)
value|if ((r = free_rectangles) == NULL)\ 					    r = Alloc_rectangle ();\ 					free_rectangles = r->next;\ 					*(RASTER *) r = rs;\ 					r->type = ty
end_define

begin_comment
comment|/* free a rectangle */
end_comment

begin_define
define|#
directive|define
name|FREERECT
parameter_list|(
name|r
parameter_list|)
value|r->next = free_rectangles; free_rectangles = r
end_define

begin_define
define|#
directive|define
name|BytePad
parameter_list|(
name|n
parameter_list|)
value|(((n) + 3)& ~3)
end_define

begin_define
define|#
directive|define
name|WordPad
parameter_list|(
name|n
parameter_list|)
value|(((n) + 3)& ~3)
end_define

begin_comment
comment|/* byte swap a long literal */
end_comment

begin_define
define|#
directive|define
name|lswapl
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0xff)<< 24) |\ 		   (((x)& 0xff00)<< 8) |\ 		   (((x)& 0xff000)>> 8) |\ 		   (((x)>> 24)& 0xff))
end_define

begin_comment
comment|/* byte swap a short literal */
end_comment

begin_define
define|#
directive|define
name|lswaps
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0xff)<< 8) | (((x)>> 8)& 0xff))
end_define

begin_comment
comment|/* byte swap a long */
end_comment

begin_define
define|#
directive|define
name|swapl
parameter_list|(
name|x
parameter_list|)
value|n = ((char *) (x))[0];\ 		 ((char *) (x))[0] = ((char *) (x))[3];\ 		 ((char *) (x))[3] = n;\ 		 n = ((char *) (x))[1];\ 		 ((char *) (x))[1] = ((char *) (x))[2];\ 		 ((char *) (x))[2] = n
end_define

begin_comment
comment|/* byte swap a short */
end_comment

begin_define
define|#
directive|define
name|swaps
parameter_list|(
name|x
parameter_list|)
value|n = ((char *) (x))[0];\ 		 ((char *) (x))[0] = ((char *) (x))[1];\ 		 ((char *) (x))[1] = n
end_define

begin_comment
comment|/* byte swap a long parameter */
end_comment

begin_define
define|#
directive|define
name|pswapl
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|n = (x)->param.b[4*(i)];\ 		     (x)->param.b[4*(i)] = (x)->param.b[4*(i)+3];\ 		     (x)->param.b[4*(i)+3] = n;\ 		     n = (x)->param.b[4*(i)+1];\ 		     (x)->param.b[4*(i)+1] = (x)->param.b[4*(i)+2];\ 		     (x)->param.b[4*(i)+2] = n
end_define

begin_comment
comment|/* byte swap a short parameter */
end_comment

begin_define
define|#
directive|define
name|pswaps
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|n = (x)->param.b[2*(i)];\ 		     (x)->param.b[2*(i)] = (x)->param.b[2*(i)+1];\ 		     (x)->param.b[2*(i)+1] = n
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|swaptype
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|swaptype
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|TRUE
parameter_list|(
name|b
parameter_list|)
value|((b)& 1)
end_define

begin_define
define|#
directive|define
name|FALSE
parameter_list|(
name|b
parameter_list|)
value|(!((b)& 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRUE
parameter_list|(
name|b
parameter_list|)
value|(b)
end_define

begin_define
define|#
directive|define
name|FALSE
parameter_list|(
name|b
parameter_list|)
value|(!(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

