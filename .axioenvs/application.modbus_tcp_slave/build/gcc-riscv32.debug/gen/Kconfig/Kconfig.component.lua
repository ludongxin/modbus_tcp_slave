
menuconfig LUA
    bool "LUA"
    libsafe 
    default n
    help
        Version: 5.3.7

        
if LUA


osource  "$(ax_imp_paths,lua_adapter_interface,,False)"

endif #LUA

