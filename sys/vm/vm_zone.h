begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998 John S. Dyson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *	notice immediately at the beginning of the file, without modification,  *	this list of conditions, and the following disclaimer.  * 2. Absolutely no warranty of function or purpose is made by the author  *	John S. Dyson.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZONE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZONE_H
end_define

begin_define
define|#
directive|define
name|ZONE_INTERRUPT
value|1
end_define

begin_comment
comment|/* Use this if you need to allocate at int time */
end_comment

begin_define
define|#
directive|define
name|ZONE_BOOT
value|16
end_define

begin_comment
comment|/* This is an internal flag used by zbootinit */
end_comment

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_typedef
typedef|typedef
name|uma_zone_t
name|vm_zone_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static void		 vm_zone_init(void); static void		 vm_zone_init2(void);  static vm_zone_t	 zinit(char *name, int size, int nentries,                      int flags, int zalloc); int		 zinitna(vm_zone_t z, struct vm_object *obj, char *name,                      int size, int nentries, int flags, int zalloc); void		 zbootinit(vm_zone_t z, char *name, int size,                      void *item, int nitems); static void		 zdestroy(vm_zone_t z); static void		*zalloc(vm_zone_t z); static void		 zfree(vm_zone_t z, void *item);
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vm_zone_init2
parameter_list|()
value|uma_startup2()
end_define

begin_define
define|#
directive|define
name|zinit
parameter_list|(
name|name
parameter_list|,
name|size
parameter_list|,
name|nentries
parameter_list|,
name|flags
parameter_list|,
name|zalloc
parameter_list|)
define|\
value|uma_zcreate((name), (size), NULL, NULL, NULL, NULL, UMA_ALIGN_PTR, UMA_ZONE_NOFREE)
end_define

begin_define
define|#
directive|define
name|zdestroy
parameter_list|()
end_define

begin_define
define|#
directive|define
name|zalloc
parameter_list|(
name|z
parameter_list|)
value|uma_zalloc((z), M_WAITOK)
end_define

begin_define
define|#
directive|define
name|zfree
parameter_list|(
name|z
parameter_list|,
name|item
parameter_list|)
value|uma_zfree((z), (item))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ZONE_H */
end_comment

end_unit

