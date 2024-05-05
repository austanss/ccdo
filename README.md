# ccdo [WIP]
### Status
This project is still in early development, and not ready for any functional use.
## Overview
**ccdo**, preferably stylized as "CCDo", aims to be a general-purpose, versatile, reliable, automated, and configurable centralized build system targeted for the C/C++ programming language toolchain.
### Design Goals
The design vision for this system is to function to the end user in a very similar manner to that of the unified `dotnet` build system.

**Hypothetical Usage:**
```sh
# assume CWD, assume ccdo.xml
ccdo build
# or specify CWD, assume ccdo.xml
ccdo build ./
# or specify CWD, specify ccdo.xml
ccdo build ./ccdo.xml
```
**Hypothetical Configuration:**
```xml
<!-- ./ccdo.xml -->
<?xml version="1.0" encoding="UTF-8"?>
<config>
    <target>
        <!-- x86-all, x86-32, x86-64 (ARM TBD) -->                       
        <cpu>x86-all</cpu>
        <!-- linux, windows (others TBD) -->
        <host>linux</host>
    </target>
    <!-- other options TBD, this revision is not final -->
</config>
```
## Development
### Timeline
There is no predictable timeline for the development of this project.
### Contributions
This project aims to be open to community contributions. However, because the project is still nascent, all contributions will be rejected until there is reasonable community interest and a reliable contribution process can be established.
