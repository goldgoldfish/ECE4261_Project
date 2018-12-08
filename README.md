ECE4261_Project

Requires Vivado 2018.2 library for PMODs
https://github.com/Digilent/vivado-library/releases

Copying from Git to school computers:
1: Sign into GitHub and download the zip of the branch you wish to work in.
2: Extract the project and move the folder to where you wish to keep the folder in.
3: Open the project. This should open Vivado. Vivado may complain about a a critial warning about being
    unable to open an IP file, this is ok. The file is not required.
4: Create the HDL wrapper.
5: Generate the Bitstream. Sometimes this step fails on the first attempt. Retry if this happens.
6: Export the hardware and include the bitstream.
7: Launch the SDK.
8: The first time the SDK is launched after downloading let eclipse import the hw_platform. The project
    and the bsp will not be imported so this must be done manually.
9: Go File -> Import -> General -> Existing Projects and select the folder than contains the main project.
    Select ok.
10: Eclipse will find all Project and bsp. Select them both and click Finish. Sometimes eclipse will open
    the folder but it will look like most items have not been imported. The files should appear after a 
    few minutes.