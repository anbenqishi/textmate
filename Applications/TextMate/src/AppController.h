extern NSString* const OakSessionDidChangeNotification;

@class OakFilterWindowController;

namespace find_tags
{
	enum
	{
		in_document = 1,
		in_selection,
		in_project,
		in_folder,
	};
}

@interface AppController : NSObject <NSMenuDelegate>
{
	IBOutlet NSMenu* bundlesMenu;
	IBOutlet NSMenu* themesMenu;
	IBOutlet NSMenu* spellingMenu;

	IBOutlet NSPanel* goToLinePanel;
	IBOutlet NSTextField* goToLineTextField;

	struct
	{
		std::string filter_string;
		BOOL key_equivalent;
		BOOL all_scopes;
		int search_type;
	} bundleItemSearch;
	OakFilterWindowController* filterWindowController;
}

- (IBAction)orderFrontFindPanel:(id)sender;

- (IBAction)orderFrontGoToLinePanel:(id)sender;
- (IBAction)performGoToLine:(id)sender;

- (IBAction)showBundleItemChooser:(id)sender;

- (IBAction)showPreferences:(id)sender;
- (IBAction)showBundleEditor:(id)sender;

- (void)setup;
@end

@interface AppController (Documents)
- (void)newDocument:(id)sender;
- (BOOL)loadSession:(id)sender;
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender;
@end

void OakOpenDocuments (NSArray* paths);
