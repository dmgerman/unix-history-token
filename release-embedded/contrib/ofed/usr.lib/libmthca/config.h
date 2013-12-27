begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|HAVE_IBV_DONTFORK_RANGE
end_define

begin_define
define|#
directive|define
name|HAVE_IBV_DOFORK_RANGE
end_define

begin_define
define|#
directive|define
name|HAVE_IBV_REGISTER_DRIVER
end_define

begin_define
define|#
directive|define
name|HAVE_IBV_READ_SYSFS_FILE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

