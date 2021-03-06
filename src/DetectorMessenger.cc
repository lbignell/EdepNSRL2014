//Detector Messenger Class controls UI Commands for adjusting detector params
#include "DetectorMessenger.hh"

#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
//#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
//#include "G4UIcmdWithADouble.hh"


DetectorMessenger::DetectorMessenger(
                                           DetectorConstruction* Det)
:Detector(Det)
{ 
  //Set up Directories
  Dir = new G4UIdirectory("/CustomCommands");
  Dir->SetGuidance("UI commands to modify this simulation");
  
  detDir = new G4UIdirectory("/CustomCommands/det/");
  detDir->SetGuidance("Detector Geometry Commands");
       
  AbsThicknessCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setAbsThickness",this);  
  AbsThicknessCmd->SetGuidance("Set HDPE Absorber thickness");
  AbsThicknessCmd->SetParameterName("Size",false);
  AbsThicknessCmd->SetRange("Size>0.");
  AbsThicknessCmd->SetUnitCategory("Length");
  AbsThicknessCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  


  //Commands. I think the 'this' in the argument to the command declarations
  //means that it gets the pointer of this UImessenger class.
  //UGDensityCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setUGDensity",this);
  //UGDensityCmd->SetGuidance("Set Density of Ultima Gold");
  //UGDensityCmd->SetParameterName("Density",false);
  //UGDensityCmd->SetRange("Density>0.");
  //UGDensityCmd->SetUnitCategory("Density");
  //UGDensityCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);
  
  //IGDensityCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setInstaGelDensity",this);
  //IGDensityCmd->SetGuidance("Set density of InstaGel");
  //IGDensityCmd->SetParameterName("Density",false);
  //IGDensityCmd->SetRange("Density>0.");
  //IGDensityCmd->SetUnitCategory("Density");  
  //IGDensityCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);
  
  //GlassDensityCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setGlassDensity",this);
  //GlassDensityCmd->SetGuidance("Set density of glass vial");
  //GlassDensityCmd->SetParameterName("Density",false);
  //GlassDensityCmd->SetRange("Density>0.");
  //GlassDensityCmd->SetUnitCategory("Density");    
  //GlassDensityCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);
  
  //AirDensityCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setAirDensity",this);
  //AirDensityCmd->SetGuidance("Set Air Density.");
  //AirDensityCmd->SetParameterName("Density",false);
  //AirDensityCmd->SetRange("Density>0.");
  //AirDensityCmd->SetUnitCategory("Density");    
  //AirDensityCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);

  //InnerRadCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setInnerRad",this);  
  //InnerRadCmd->SetGuidance("Set Inner Radius of Glass Vial");
  //InnerRadCmd->SetGuidance("Make Sure Inner Rad < Outer Rad");
  //InnerRadCmd->SetGuidance("Inner Rad must be > 10mm");
  //InnerRadCmd->SetParameterName("Size",false);
  //InnerRadCmd->SetRange("Size>10.");
  //InnerRadCmd->SetUnitCategory("Length");
  //InnerRadCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  

  //OuterRadCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setOuterRad",this);  
  //OuterRadCmd->SetGuidance("Set Outer Radius of Glass Vial");
  //OuterRadCmd->SetGuidance("Make Sure Inner Rad < Outer Rad");
  //OuterRadCmd->SetParameterName("Size",false);
  //OuterRadCmd->SetRange("Size>10.");
  //OuterRadCmd->SetUnitCategory("Length");
  //OuterRadCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  

  //BaseThicknessCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setBaseThickness",this);  
  //BaseThicknessCmd->SetGuidance("Set Half-Height of base of Glass Vial");
  //BaseThicknessCmd->SetParameterName("Size",false);
  //BaseThicknessCmd->SetRange("Size>0.");
  //BaseThicknessCmd->SetUnitCategory("Length");
  //BaseThicknessCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  

  //ScintillantVolumeCmd = new G4UIcmdWithADoubleAndUnit("/CustomCommands/det/setScintillantVolume",this);  
  //ScintillantVolumeCmd->SetGuidance("Set Volume of scintillant");
  //ScintillantVolumeCmd->SetParameterName("Size",false);
  //ScintillantVolumeCmd->SetRange("Size>0.");
  //ScintillantVolumeCmd->SetUnitCategory("Volume");
  //ScintillantVolumeCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  

  //UGCompCCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompC", this);
  //UGCompCCmd->SetGuidance("Set percentage carbon of UG Scintillant, value must be between 0 and 1");
  //UGCompCCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);

  //UGCompHCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompH", this);
  //UGCompHCmd->SetGuidance("Set percentage Hydrogen of UG Scintillant, value must be between 0 and 1");
  //UGCompHCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //UGCompNCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompN", this);
  //UGCompNCmd->SetGuidance("Set percentage Nitrogen of UG Scintillant, value must be between 0 and 1");
  //UGCompNCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //UGCompOCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompO", this);
  //UGCompOCmd->SetGuidance("Set percentage Oxygen of UG Scintillant, value must be between 0 and 1");
  //UGCompOCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //UGCompNaCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompNa", this);
  //UGCompNaCmd->SetGuidance("Set percentage Sodium of UG Scintillant, value must be between 0 and 1");
  //UGCompNaCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //UGCompPCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompP", this);
  //UGCompPCmd->SetGuidance("Set percentage Phosphorus of UG Scintillant, value must be between 0 and 1");
  //UGCompPCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //UGCompSCmd = new G4UIcmdWithADouble("/CustomCommands/det/setUGCompS", this);
  //UGCompSCmd->SetGuidance("Set percentage Sulphur of UG Scintillant, value must be between 0 and 1");
  //UGCompSCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);


  //ScintillantSetCmd = new G4UIcmdWithAString("/CustomCommands/det/setScintillant",this);  
  //ScintillantSetCmd->SetGuidance("Set Scintillant");
  //ScintillantSetCmd->SetGuidance("This Command was cut for causing problems and DOES NOT WORK!");
  //ScintillantSetCmd->SetParameterName("choice",false);
  //ScintillantSetCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);  

  UpdateCmd = new G4UIcmdWithoutParameter("/CustomCommands/det/update",this);
  UpdateCmd->SetGuidance("Update calorimeter geometry.");
  UpdateCmd->SetGuidance("This command MUST be applied before \"beamOn\" ");
  UpdateCmd->SetGuidance("if you changed geometrical value(s).");
  UpdateCmd->AvailableForStates(G4State_PreInit,G4State_Idle,G4State_GeomClosed,G4State_EventProc);
      
}


DetectorMessenger::~DetectorMessenger()
{
  delete UpdateCmd;
  delete AbsThicknessCmd;
  //  delete ScintillantSetCmd; delete ScintillantVolumeCmd;
  //delete BaseThicknessCmd; delete OuterRadCmd;
  //delete InnerRadCmd;   delete AirDensityCmd;
  //delete GlassDensityCmd;
  //delete IGDensityCmd;
  //delete UGDensityCmd;  
  delete detDir;
  delete Dir;
}


void DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  //if( command ==  UGDensityCmd)
  // { Detector->SetUGDensity(UGDensityCmd->GetNewDoubleValue(newValue));}
   
  //if( command == IGDensityCmd)
  //{ Detector->SetIGDensity(IGDensityCmd->GetNewDoubleValue(newValue));}
  
  //if( command == GlassDensityCmd)
  //{ Detector->SetGlassDensity(GlassDensityCmd->GetNewDoubleValue(newValue));}
   
  //if( command == AirDensityCmd)
  //{ Detector->SetAirDensity(AirDensityCmd->GetNewDoubleValue(newValue));}
   
  //if( command == InnerRadCmd)
  //{ Detector->SetInnerRadius(InnerRadCmd->GetNewDoubleValue(newValue));}
   
  //if( command == OuterRadCmd)
  //{ Detector->SetOuterRadius(OuterRadCmd->GetNewDoubleValue(newValue));}
  
  if( command == UpdateCmd)
    { Detector->UpdateGeometry(); }

  if( command == AbsThicknessCmd)
    { Detector->SetAbsThickness(AbsThicknessCmd->GetNewDoubleValue(newValue));}


  //if( command == BaseThicknessCmd)
  // { Detector->SetBaseThickness(BaseThicknessCmd->GetNewDoubleValue(newValue));}
  //if( command == ScintillantVolumeCmd)
  //{ Detector->SetScintillantVolume(ScintillantVolumeCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompCCmd)
  //{ Detector->SetUGCompC(UGCompCCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompHCmd)
  //{ Detector->SetUGCompH(UGCompHCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompNCmd)
  //{ Detector->SetUGCompN(UGCompNCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompOCmd)
  //{ Detector->SetUGCompO(UGCompOCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompNaCmd)
  //{ Detector->SetUGCompNa(UGCompNaCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompPCmd)
  //{ Detector->SetUGCompP(UGCompPCmd->GetNewDoubleValue(newValue));}

  //if( command == UGCompSCmd)
  //{ Detector->SetUGCompS(UGCompSCmd->GetNewDoubleValue(newValue));}

  //if( command == ScintillantSetCmd)
  //{ Detector->SetScintillant(newValue);}

}
