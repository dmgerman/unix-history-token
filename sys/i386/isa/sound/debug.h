begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Kernel driver debugging stuff - cmetz@thor.tjhsst.edu */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEBUG_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_ME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HALT_DEBUGGING
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|X
parameter_list|)
value|printk("%s %s: ", __FILE__, __FUNCTION__); X
end_define

begin_define
define|#
directive|define
name|DEB1
parameter_list|(
name|X
parameter_list|)
value|printk("%s %s: ", __FILE__, __FUNCTION__); X
end_define

begin_define
define|#
directive|define
name|RETURN_HEX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|{ Y _foo; _foo = X; printk("%s %s: 0x%x\n", __FILE__, __FUNCTION__, ((int)_foo)); return(_foo); }
end_define

begin_define
define|#
directive|define
name|RETURN_DEC
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|{ Y _foo; _foo = X; printk("%s %s: %d\n", __FILE__, __FUNCTION__, ((int)_foo)); return(_foo); }
end_define

begin_define
define|#
directive|define
name|RETURN_PTR
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|{ Y _foo; _foo = X; printk("%s %s: 0x%08x\n", __FILE__, __FUNCTION__, ((void *)_foo)); return(_foo); }
end_define

begin_define
define|#
directive|define
name|RETURN_ERR
parameter_list|(
name|X
parameter_list|)
value|{ int _foo; _foo = X; printk("%s %s: ", __FILE__, __FUNCTION__); switch(_foo) { case 0: printk("No error"); break; case -ENODEV: printk("ENODEV"); break; case -EBUSY: printk("EBUSY"); break; default: printk("Error %d", _foo); } printk(".\n"); return(_foo); }
end_define

begin_define
define|#
directive|define
name|DEB_OUTB
value|OUTB
end_define

begin_define
define|#
directive|define
name|DEB_INB
value|INB
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEB1
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RETURN_HEX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|return(X)
end_define

begin_define
define|#
directive|define
name|RETURN_DEC
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|return(X)
end_define

begin_define
define|#
directive|define
name|RETURN_PTR
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|return(X)
end_define

begin_define
define|#
directive|define
name|RETURN_ERR
parameter_list|(
name|X
parameter_list|)
value|return(X)
end_define

begin_define
define|#
directive|define
name|DEB_OUTB
value|OUTB
end_define

begin_define
define|#
directive|define
name|DEB_INB
value|INB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

