rem msbuild uc_engine.vcxproj /t:Build /p:Configuration=release /p:Platform=x64 /verbosity:detailed
rem msbuild ucdev_app.vcxproj /t:Clean /p:Configuration=release /p:Platform=x64 /verbosity:detailed
msbuild ucdev_app.vcxproj /t:Build /p:Configuration=debug /p:Platform=x64 /verbosity:detailed /p:DeployOnBuild=true


