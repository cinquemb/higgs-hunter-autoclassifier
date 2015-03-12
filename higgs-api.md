# URL FOR GETTING IMAGE OBJECTS #
https://api.zooniverse.org/projects/higgs_hunter/subjects?limit=10

# SAMPLE OBJECT DATA #
{"id":"5460d153b0c782277800bd3f","activated_at":"2014-11-13T15:47:45Z","classification_count":10,"coords":[],"created_at":"2014-11-13T12:16:11Z","location":{"standard":["http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/standard/5460d153b0c782277800bd3f_0.png","http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/standard/5460d153b0c782277800bd3f_1.png","http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/standard/5460d153b0c782277800bd3f_2.png"],"thumbnail":["http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/thumbnail/5460d153b0c782277800bd3f_0.png","http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/thumbnail/5460d153b0c782277800bd3f_1.png","http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/thumbnail/5460d153b0c782277800bd3f_2.png"]},"metadata":{"counters":{"1":6,"2":4},"data_type":"not_sim","image_metadata":[{"name":"hZ_dvdv_8GeV_tautau_1mm/atlantisRZzoom_110202955_013885.png","group":"hZ_dvdv_8GeV_tautau_1mm","view":"RZzoom"},{"name":"hZ_dvdv_8GeV_tautau_1mm/atlantisXY_110202955_013885.png","group":"hZ_dvdv_8GeV_tautau_1mm","view":"XY"},{"name":"hZ_dvdv_8GeV_tautau_1mm/atlantisXYzoom_110202955_013885.png","group":"hZ_dvdv_8GeV_tautau_1mm","view":"XYzoom"}]},"project_id":"545b9c49b0c7823037000001","random":0.9524030168351707,"state":"active","updated_at":"2014-11-13T12:16:11Z","workflow_ids":["545b9c57b0c7823037000002"],"zooniverse_id":"AHH0000201"}


# URL FOR SUBMITING ANALYSIS #
https://api.zooniverse.org/projects/higgs_hunter/workflows/545b9c57b0c7823037000002/classifications

# SAMPLE HEADERS FOR SENDING ANALYSIS #
Host: api.zooniverse.org
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:32.0) Gecko/20100101 Firefox/32.0
Accept: application/json, text/javascript, */*; q=0.01
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded; charset=UTF-8
X-Zooniverse-Origin: http://www.higgshunters.org
X-Requested-With: XMLHttpRequest
Referer: https://api.zooniverse.org/proxy
Content-Length: 1836
Connection: keep-alive
Pragma: no-cache
Cache-Control: no-cache

Host: api.zooniverse.org
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:32.0) Gecko/20100101 Firefox/32.0
Accept: application/json, text/javascript, */*; q=0.01
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded; charset=UTF-8
Authorization: Basic Y2lucXVlbWI6MjU3MDlkZGE0ODI4NjlhM2Q5OTM=
X-Zooniverse-Origin: http://www.higgshunters.org
X-Requested-With: XMLHttpRequest
Referer: https://api.zooniverse.org/proxy
Content-Length: 1478
Connection: keep-alive
Pragma: no-cache
Cache-Control: no-cache

# SAMPLE BODY FOR SENDING ANALYSIS  (url encode before sending, no new lines)#
#how_many: 2,3,4, 5-10,10+#

classification[subject_ids][]=5460d07fb0c7822778004d31&
classification[annotations][0][key]=pickOne&
classification[annotations][0][value][0][x]=532.498&
classification[annotations][0][value][0][y]=540.161&
classification[annotations][0][value][0][value]=vertex&
classification[annotations][0][value][0][frame]=2&
classification[annotations][0][value][0][how_many]=3&
classification[annotations][0][value][1][x]=567.544&
classification[annotations][0][value][1][y]=490.097&
classification[annotations][0][value][1][value]=vertex&
classification[annotations][0][value][1][frame]=2&
classification[annotations][0][value][1][how_many]=5-10&
classification[annotations][1][started_at]=Fri, 28 Nov 2014 23:11:45 GMT&
classification[annotations][1][finished_at]=Fri, 28 Nov 2014 23:13:04 GMT&
classification[annotations][2][user_agent]=Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:32.0) Gecko/20100101 Firefox/32.0&
classification[annotations][3][image_index]=2&
classification[annotations][4][image_src]=http://zooniverse-static.s3.amazonaws.com/higgs_hunter/subjects/standard/5460d07fb0c7822778004d31_2.png&classification[annotations][5][workflow]=untitled_workflow