# VISCOWAVE VERSION 2.0.0

## VERSION 2.0.0 RELEASE NOTES
ViscoWave Version 2.0.0 brings several updates to the previous version of ViscoWave. These updates include the following.
1.	**Pre-Processing** for extracting ViscoWave-compatible CSV files from FWD data files.
2.	**Batch-Processing** for backcalculating multiple time histories.
3.	**Post-Processing** for summarizing backcalculated results from batch-processing. 
4.	**Constrained Backcalculation** with lower and upper bounds for layer moduli.

With the release of Version 2.0.0, the previous version of ViscoWave has been archived. A detailed user manual is coming soon!

## INTRODUCTION

**ViscoWave** is a dynamic Finite Layer Method (FLM) which is capable of modeling the dynamics (i.e., transient stress wave propagation) of a variety of flexible pavement structures with elastic/viscoelastic layers, with/without bedrock (Lee, 2013 & 2014).  As shown in the figure below, the FLM is similar to the Finite Element Method (FEM) in the sense that the entire pavement structure is broken down into smaller elements for the analysis.  
<img src="Release Notes/Figures/FEM_vs_FLM.jpg" ></img>

The FEM requires each layer of the pavement be divided into a large number of smaller elements to ensure accurate and reliable results.  Due to the large number of elements, FEM usually is computationally expensive, which may be undesirable for backcalculation.  

On the other hand, the fundamental concept behind the FLM is to define an entire layer (or sublayer) as a single element; thus for a 3-layer pavement system, FLM only needs 3 elements.  This is made possible by taking advantage of the simplified geometry of each pavement layer (see above figure on the right) and solving the wave equations analytically (or semi-analytically). In other words, the phenomenon of stress wave propagation within a given layer is solved in closed-form or semi closed-form.  The interaction between multiple layers (or elements in this case) and the boundary conditions are then accounted for in the same manner as the FEM.

A unique characteristic of ViscoWave which separates it from other available FLM solutions (e.g., SAPSI-M by Chatti and Yun, 1996; 3D-Move by Siddharthan et. al., 2000; LAMDA by Al-Khoury et. al., 2001) is that ViscoWave is based on impulse loading and responses. The following figure shows the conceptual schematics on how the impulse loading and responses are used in ViscoWave for obtaining the overall pavement response under a time-dependent, Falling Weight Deflectometer (FWD) type of loading. The details regarding the formulation of ViscoWave is documented in Lee (2013, 2014).

<img src="Release Notes/Figures/Impulse_Load_Response.jpg " ></img>


## INSTALLING VISCOWAVE

Installation of ViscoWave is simple. Download the "[ViscoWave_V2_Installer.zip](ViscoWave_V2_Installer.zip)" and extract the files to a local directory. Then double click the Setup.exe file. Follow the on-screen instructions to complete installation.  

It is also strongly recommended that you also download and execute “[Portable_R_for_VW.msi](https://www.dropbox.com/s/ehssdvv2u8vhylx/Portable_R_for_VW.msi?dl=0)” to install Portable R in your machine. **Portable R** is needed for Pre-Processing of the FWD data (i.e., extracting time history CSV files). 

If you do not wish to install Portable R, you will have to run the R-script generated by ViscoWave in Standard R (with or without RStudio), outside the ViscoWave environment. This option is not recommended unless you have sufficient knowledge in R language.  

**Notes on ViscoWave installation:**
* Installation of ViscoWave requires that the user has **Administrator Access** to the computer.
* ViscoWave (and its installer) has only been tested on **64-bit Windows 10 Environment, with 32-bit or 64-bit Microsot Excel**.

## GETTING STARTED

Once ViscoWave is installed, you should see a ViscoWave shortcut created on your Windows Desktop. Double-click on the shortcut to open the ViscoWave interface built in the Microsoft Excel environment. 

**Notes on ViscoWave interface:**
* This is a **“Read-Only”** file. Please save the template with a different file name if you do not want to lose your changes.
* You need to have some basic knowledge of Microsoft Excel.

**ViscoWave Excel interface** has the following 5 tabs (that are visible by default):

1.	**VW** – Tab for ViscoWave main menu as well as forward simulation and backcalculation.. 
2.	**Default Inputs** – Tab for storing the default (or seed) pavement parameters (Modulus, Poisson’s Ratio, Density, Thickness, and Damping) and their constraints.
3.	**Dynamic_Modulus_Calc** – Tab for converting the Relaxation Modulus (in time-domain) to Dynamic Modulus (in frequency-domain), or vice versa. 
4.	**VW_Quick_Start_Guide** – Tab including a quick reference for using ViscoWave.
5.	**AGPL License V3** – Tab showing the license agreement (AGPL Version 3.0) for ViscoWave. 

Among the above, you will mostly interact with VW and Dynamic_Modulus_Calc tabs for the analysis as described subsequently. In addition to the above, the interface includes the following 2 tabs that are hidden: 

1.	**DM_Summary** – Tab for summarizing the backcalculated Dynamic Modulus (i.e., for Viscoelastic Layers only). 
2.	**ElasticLayer_Summary** – Tab for summarizing the backcalculated Elastic Modulus (i.e., for Elastic Layers).

These 2 tabs are only reserved for summarizing the backcalculated results from batch-mode processing. As a user, you do not need to worry about these tabs. 


## VISCOWAVE ANALYSIS MENU OPTIONS

The figure below shows the ViscoWave Main Menu options that can be found within the VW tab. Additional details regarding these menu options are provided in the subsequent sections. 

<img src="Release Notes/Figures/VW_MainMenu.png" ></img>

 
## PRE-PROCESSING OF FWD DATA

Pre-processing of the FWD data allows you to extract deflection summaries as well as ViscoWave-compatible time history CSV files. You need to select one of the three FWD types (Dynatest, JILS, and Kuab FWDs) for extracting the necessary files for backcalculation. The program will ask you to select the FWD data for pre-processing.  The compatible FWD files and folder structures are described below.  

1.	For **Dynatest FWD**, browse and select the __*.mdb file__ which includes all data (peak deflections, time histories, temperature, etc.) needed for pre-processing (See figure below). 
2.	For **JILS FWD**, the peak deflections are saved in the __*.DAT file__ while the time histories for all drops are stored in __*.THY file__. Both these files should have the same name (e.g., JILS.DAT and JILS.THY) and be placed in the same path. You may select either file for pre-processing (See figure below). 
3.	For **Kuab FWD**, the peak deflections are saved in the __*.fwd file__ while the time histories for each drop are stored in __*.HST file__ (i.e., there are multiple *.HST files corresponding to one *.fwd file). All these files need should be placed in the same path. When prompted by the program, select the folder that contains all these files (See figure below).

 <img src="Release Notes/Figures/Selecting_FWD_Data_File.png" ></img>


Once you select the FWD data for pre-processing the code produces the following outputs. These files are stored in the same folder as the original FWD data. 

1.	CSV files containing the peak load and deflections along with other information stored in the FWD files (e.g., station, temperature, drop number, etc.). See left figure below for an example. 
2.	FWD peak deflection plots along the station values provided in the FWD data. See right figure below for an example. 
<img src="Release Notes/Figures/Peak_Defl_Summary.png" ></img>

 

3.	CSV files including the FWD load and deflection time-history data for every test (in the CSV folder). The CSV files are compatible with ViscoWave and can be inputted directly into the ViscoWave interface for simulation or backcalculation. See left figure below for an example.
4.	Load and deflection time history plots for every FWD drop included in the raw data file. See right figure below for an example.  

  <img src="Release Notes/Figures/TimeHistory_CSVs.png" ></img>


Although the peak deflections are not used for dynamic backcalculation, it is always good practice to investigate the peak deflections for identifying any outliers or non-decreasing deflections to be excluded from the analysis, and/or for determining any trends within the data. 

Similarly, you may want to go through the time history plots to ensure they are smooth and no issues or outliers are found (at least visually). You can easily go through these figures in any image viewing app (e.g., Windows application Photos). Here is an example of a “good” versus “bad” time history. Do not use any of these “bad” looking time histories for backcalculation. 

   <img src="Release Notes/Figures/Good_vs_Bad_TimeHistory.png" ></img>


**Notes on Pre-Processing:**

•	Samples of Dynatest, JILS, and Kuab FWD files are provided in [Dropbox]( https://www.dropbox.com/sh/d0dxthyuhfu6vc1/AABOplpBskALIptieVXm_0Ala?dl=0)

## FORWARD SIMULATION USING VISCOWAVE

Running ViscoWave is easy!  In the VW tab, simply fill in the pavement structure information as well as sensor offsets, FWD plate radius, and the FWD load time history as shown in the figure below. The simulation results will automatically be updated. 

 
  <img src="Release Notes/Figures/ViscoWave_Input_Screen.png" ></img>
 
  <img src="Release Notes/Figures/ViscoWave_Defl_Plots.png" ></img>


**Notes on ViscoWave inputs:**

•	To simulate a **viscoelastic layer**, the modulus of that particular layer must be assigned a value of ZERO in the General Pavement Structure table, and the sigmoidal function coefficients should be provided in the table below it.

•	To simulate a **half-space (i.e., a semi-infinite subgrade)**, the thickness of the last layer must be specified to ZERO. However, It is generally recommended NOT to use a half-space for backcalculation purposes – use a very thick subgrade instead (e.g., 300 in. to 500 in. subgrade thickness).

•	Current ViscoWave interface allows up to 6 pavement layers (including 3 viscoelastic layers) and 9 deflection sensors. This is simply due to the interface, not the limitation of ViscoWave code.


The VW tab also allows you to generate a few synthetic load time histories: Half-Sine, Haver-Sine, and Normal (Gaussian) shaped loads. Simply fill in the necessary inputs for the load you want then click on the corresponding button to generate the load. 

 <img src="Release Notes/Figures/VW_TimeHistory.png" ></img>


**Notes on ViscoWave time histories:**

•	**Time Increment** (dt) must be **0.2 milliseconds** (Hard Coded in C++ Code).
•	**Maximum time** should NOT exceed 0.06 seconds. It is generally recommended not to modify the time column. In other words, use the time from 0 to 0.0598 sec. at an interval of 0.002 sec.

## BACKCALCULATION USING VISCOWAVE (SINGLE DROP)

**Backcalculation of a single FWD time history** can be done entirely within the "VW" worksheet (Assuming the CSV files were extracted from the FWD data using the pre-processing options). To backcalculate the pavement properties from a single CSV file, follow these steps: 


1.	Import the CSV file by clicking on the "Import Measured Time History" button and selecting the CSV file to be analyzed. 
2.	Fill out the pavement/materials related input (i.e., pavement thickness, modulus, sigmoid coefficients, etc.), until there is a reasonable agreement between the measured and simulated time histories.
3.	Fill out the constraints if constrained backcalculation is intended.
4.	Try backcalculating the layer moduli (Unconstrained or Constrained, as desired).
5.	If the backcalculated results are not satisfactory, try backcalculating with a different set of seed values.
6.	If the backcalculated results are satisfactory, these results can be exported to the "Default Inputs" worksheet (if desired).

  <img src="Release Notes/Figures/VW_Constraints.png" ></img>


Note that the Sigmoidal Function used in ViscoWave (in the VW tab) corresponds to the Relaxation Modulus in time-domain. If you need to convert Relaxation Modulus to Dynamic Modulus (or Vice Versa), follow the instructions in the following section.

## CONVERTING RELAXATION MODULUS TO DYNAMIC MODULUS

As discussed above, the Sigmoidal Function for ViscoWave (in the VW tab) corresponds to the Relaxation Modulus in time-domain. The **Dynamic_Modulus_Calc** tab allows you to convert the Relaxation Modulus (in time-domain) to Dynamic modulus (in frequency-domain). Similarly, if you have Dynamic Modulus Sigmoidal Coefficients (say from laboratory testing of asphalt mixtures), and want to use them in ViscoWave, this tab also allows you to convert the Dynamic Modulus to Relaxation Modulus. 

•	To convert from **Relaxation Modulus** (E(t)) to **Dynamic Modulus** (|E*|), simply fill in the Relaxation coefficients (Top Left table) and click on the button “Convert E(t) to |E*|”.
•	To convert from **Dynamic Modulus** (|E*|) to **Relaxation Modulus** (E(t)), simply fill in the Relaxation coefficients (Top Right table) and click on the button “Convert |E*| to E(t)”.

The tab also provides the Prony series coefficients that can be used to calculate both the Relaxation and Dynamic moduli. 

   <img src="Release Notes/Figures/Sigmoidal_and_Prony_Coefficients.png" ></img>



The tab also shows the plots for the Relaxation and Dynamic moduli from both the Sigmoidal functions and Prony series. 

   <img src="Release Notes/Figures/Modulus_Plots.png" ></img>


## BACKCALCULATION USING BATCH MODE

Batch mode backcalculation allows for backcalculating multiple FWD drops. You can run either the **Constrained** or the **Unconstrained** backcalculation by clicking on the appropriate button in the main menu. Some important notes are provided in the following.

1.	When you run batch mode, the Seed values stored in the "**Default Inputs**" worksheet are used as seed values for backcalculating all CSV files selected. Because Seed values are very important, **it is strongly recommended that you run manual backcalculation on at least one of the CSV files and export the satisfactory results to the "Default Inputs" (i.e., Step 6 of Manual Backcalculation) before running batch mode backcalculation**. 
2.	Similarly, in case of constrained backcalculation, the Constraints stored in the "Default Inputs" become active for all CSVs selected for batch mode processing. 
3.	The batch mode processing automatically converts the Relaxation Modulus coefficients to Dynamic Modulus coefficients (Step 7 of Single Drop Backcalculation).
4.	The backcalculated ViscoWave file (.xlsm file) is saved automatically with the same name as the CSV file.


## POST-PROCESSING FOR BATCH MODE BACKCALCULATION

Post-processing option gathers the backcalculated modulus from the individual ViscoWave (*.xlsm) files produced from batch processing, and calculates the average modulus for each layer. In addition, for the asphalt concrete (i.e., viscoelastic layer), the inputs needed for Mechanistic-Empirical (ME) design are calculated. 

To run post-processing, click on the "**Generate Backcalculation Summary**" button and select the *.xlsm files produced from batch processing. Post-processing produces the following summary worksheets. 

1.	**DM_Summary worksheet** which includes the dynamic modulus from the individual backcalculation as well as the overall average dynamic modulus. The worksheet also provides the dynamic modulus values that can be used for ME design.

 
    <img src="Release Notes/Figures/DM_Summary_Table.png" ></img>

    <img src="Release Notes/Figures/DM_Summary_Plots.png" ></img>

 


2.	**ElasticLayer_Summary** worksheet which includes the elastic modulus from the individual backcalculation as well as the average modulus values for each elastic layer included in the pavement structure.


     <img src="Release Notes/Figures/EM_Summary_Table.png" ></img>

    <img src="Release Notes/Figures/EM_Summary_Plots.png" ></img>

 


## REFERENCES

Al-Khoury, R., Skarpas, A., Kasbergen, C., and Blaauwendraad, J., Spectral element technique for efficient parameter identification of layered media. I. Forward calculation. International Journal of Solids and Structures, Vol. 38, No. 9, 2001, pp. 1605-1623.

Chatti, K., and Yun, K.K., SAPSI-M: Computer Program for Analyzing Asphalt Concrete Pavements under Moving Arbitrary Loads. In Transportation Research Record 1539, TRB, National Research Council, Washington, D.C., 1996, pp. 88–95. 

Lee, H.S. 2013. Development of a New Solution for Viscoelastic Wave Propagation of Pavement Structures and Its Use in Dynamic Backcalculation. Ph. D. Dissertation. Michigan State University. 

Lee, H.S. 2014. ViscoWave – A New Solution for Viscoelastic Wave Propagation of Layered Structures Subjected to an Impact Load. International Journal of Pavement Engineering, 15(6): 542-557.

Siddharthan, R.V., Krishnamenon, N., and Sebaaly, P.E., Finite-Layer Approach to Pavement Response Evaluation. In Transportation Research Record 1706, TRB, National Research Council, Washington, D.C., 2000, pp. 43–49.
