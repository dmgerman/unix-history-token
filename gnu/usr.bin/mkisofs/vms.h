begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file mkisofs.h - assorted structure definitions and typecasts.     Written by Eric Youngdale (1993).    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|VMS_stat(X,Y)
end_define

begin_define
define|#
directive|define
name|lstat
value|VMS_stat
end_define

begin_comment
comment|/* gmtime not available under VMS - make it look like we are in Greenwich */
end_comment

begin_define
define|#
directive|define
name|gmtime
value|localtime
end_define

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|X
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|X
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|X
parameter_list|)
value|(((X)& S_IFMT) == S_IFREG)
end_define

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|X
parameter_list|)
value|(((X)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

